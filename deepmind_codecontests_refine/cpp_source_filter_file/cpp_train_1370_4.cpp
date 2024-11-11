#include <bits/stdc++.h>
using namespace std;
struct node {
  int id;
  int parent;
  int minimum_root_distance;
  int maximum_root_distance;
  node(int _id, int _parent, int _minimum_root_distance,
       int _maximum_root_distance) {
    id = _id;
    parent = _parent;
    minimum_root_distance = _minimum_root_distance;
    maximum_root_distance = _maximum_root_distance;
  }
  bool has_clear_distance() {
    return minimum_root_distance == maximum_root_distance - 1;
  }
  void update_distance(int light, int distance) {
    if (has_clear_distance()) return;
    if (light == 1)
      maximum_root_distance = distance + 1;
    else
      minimum_root_distance = distance + 1;
  }
  void info() {
    cerr << "node " << id << " parent " << parent << " range("
         << minimum_root_distance << ", " << maximum_root_distance << ")"
         << endl;
  }
};
int total_vertices;
vector<node> nodes;
vector<int> question(vector<int> quest) {
  vector<int> result;
  cout << "? ";
  for (int i = 0; i < quest.size(); i++) cout << quest[i] << " ";
  cout << endl;
  char answer;
  for (int i = 0; i < quest.size(); i++) {
    cin >> answer;
    result.push_back(int(answer - '0'));
  }
  return result;
}
bool has_unknown_distance() {
  for (int i = 0; i < total_vertices; i++)
    if (!nodes[i].has_clear_distance()) return true;
  return false;
}
void find_clear_distances(vector<int> &distance) {
  int maximum = 0;
  for (int i = 0; i < total_vertices; i++) {
    if (nodes[i].has_clear_distance())
      distance.push_back(nodes[i].minimum_root_distance);
    maximum = max(maximum, nodes[i].maximum_root_distance);
  }
  sort(distance.begin(), distance.end());
  distance.erase(unique(distance.begin(), distance.end()), distance.end());
  distance.push_back(maximum);
}
void find_distance_clusters(vector<vector<int> > &clusters) {
  for (int i = 0; i < total_vertices; i++) clusters.push_back(vector<int>());
  for (int i = 0; i < total_vertices; i++)
    if (nodes[i].has_clear_distance())
      clusters[nodes[i].minimum_root_distance].push_back(i);
}
void update_distance_quest(vector<int> &quest, vector<int> &cluster,
                           int distance) {
  for (int i = 0; i < cluster.size(); i++) quest[cluster[i]] = distance;
}
void update_distance_clusters(int start, int diff, vector<int> &distance,
                              vector<vector<int> > &cluster) {
  vector<int> quest;
  for (int i = 0; i < total_vertices; i++) quest.push_back(0);
  for (int i = start; i < distance.size() - 1; i += 2) {
    int beg = distance[i];
    int end = distance[i + 1];
    if (beg + 1 != end) {
      int mid = (beg + end) / 2 - diff;
      if (mid != beg) update_distance_quest(quest, cluster[beg], mid - beg);
    }
  }
  bool flag = false;
  for (int i = 0; i < quest.size(); i++)
    if (quest[i] > 0) flag = true;
  if (!flag) return;
  vector<int> answer = question(quest);
  for (int i = start; i < distance.size() - 1; i += 2) {
    int beg = distance[i];
    int end = distance[i + 1];
    if (beg + 1 != end) {
      int mid = (beg + end) / 2 - diff;
      for (int j = 0; j < total_vertices; j++) {
        if (mid >= nodes[j].minimum_root_distance &&
            mid < nodes[j].maximum_root_distance)
          nodes[j].update_distance(answer[j], mid);
      }
    }
  }
}
void find_distances() {
  vector<int> distance;
  vector<vector<int> > cluster;
  while (has_unknown_distance()) {
    distance.clear();
    cluster.clear();
    find_distance_clusters(cluster);
    find_clear_distances(distance);
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        update_distance_clusters(i, j, distance, cluster);
  }
}
void find_parents() {
  int maximum = 0;
  for (int i = 0; i < total_vertices; i++)
    maximum = max(maximum, nodes[i].minimum_root_distance);
  vector<vector<int> > cluster;
  for (int i = 0; i <= maximum; i++) cluster.push_back(vector<int>());
  for (int i = 0; i < total_vertices; i++)
    cluster[nodes[i].minimum_root_distance].push_back(i);
  vector<int> candidate_ids;
  for (int i = 0; i < total_vertices; i++) candidate_ids.push_back(0);
  for (int remain = 0; remain < 3; remain++) {
    for (int i = 0; i < 9; i++) {
      int p = (1 << i);
      vector<int> quest;
      for (int tmp = 0; tmp < total_vertices; tmp++) quest.push_back(0);
      for (int depth = 0; depth < maximum; depth++)
        if (depth % 3 == remain) {
          vector<int> ids;
          for (int j = 0; j < cluster[depth].size(); j++)
            if (j & p) ids.push_back(j);
          for (int j = 0; j < ids.size(); j++)
            quest[cluster[depth][ids[j]]] = 1;
        }
      bool flag = false;
      for (int j = 0; j < quest.size(); j++)
        if (quest[j]) flag = true;
      if (flag == true) {
        vector<int> answer = question(quest);
        for (int j = 0; j < answer.size(); j++)
          if (answer[j] && (nodes[j].minimum_root_distance - 1) % 3 == remain)
            candidate_ids[j] |= p;
      }
    }
  }
  for (int i = 1; i < total_vertices; i++) {
    int depth = nodes[i].minimum_root_distance;
    nodes[i].parent = cluster[depth - 1][candidate_ids[i]] + 1;
  }
}
int main() {
  cin >> total_vertices;
  for (int i = 0; i < total_vertices; i++) {
    node new_node = node(i + 1, -1, 1, total_vertices);
    nodes.push_back(new_node);
  }
  nodes[0].minimum_root_distance = 0;
  nodes[0].maximum_root_distance = 1;
  find_distances();
  find_parents();
  cout << "!" << endl;
  for (int i = 1; i < total_vertices; i++) {
    cout << nodes[i].id << " " << nodes[i].parent << endl;
  }
  return 0;
}
