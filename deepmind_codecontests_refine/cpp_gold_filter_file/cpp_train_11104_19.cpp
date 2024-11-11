#include <bits/stdc++.h>
using namespace std;
int nodes, edges, counter, counter2;
vector<int> adj[100001];
set<int> adjset[100001];
int seen[100001];
int low[100001];
int depth[100001];
bool iscut[100001];
set<int> group[100001];
int dfn[100001];
stack<pair<int, int> > s;
set<pair<int, int> > ins;
bool isOld[100001];
int father[100001];
void findComponents(int node) {
  if (false) cout << "Happy\n";
  isOld[node] = true;
  counter2++;
  dfn[node] = counter2;
  low[node] = dfn[node];
  while (adjset[node].size()) {
    if (false) cout << "Happier\n";
    int w = *adjset[node].begin();
    adjset[node].erase(w);
    adjset[w].erase(node);
    if (ins.count(make_pair(node, w)) == 0) {
      ins.insert(make_pair(node, w));
      ins.insert(make_pair(w, node));
      s.push(make_pair(node, w));
    }
    if (!isOld[w]) {
      father[w] = node;
      findComponents(w);
      if (low[w] >= dfn[node]) {
        iscut[node] = true;
        if (false) cout << "Happiest\n";
        while (true) {
          pair<int, int> top = s.top();
          s.pop();
          ins.erase(top);
          ins.erase(make_pair(top.second, top.first));
          group[counter].insert(top.first);
          group[counter].insert(top.second);
          if (top == make_pair(w, node) || top == make_pair(node, w)) break;
        }
        counter++;
      }
      low[node] = min(low[node], low[w]);
    } else if (w != father[node]) {
      low[node] = min(low[node], dfn[w]);
    }
  }
}
int parity[100001];
int Rank[100001];
vector<int> evenGroupOf[100001];
set<int> evenClusterOf[100001];
int islandOf[100001];
int isEven[100001];
int parent[100001];
set<int> clusterAlpha[100001];
set<int> evenCluster[100001];
map<pair<int, int>, bool> answercache;
int find(int n) {
  if (parent[n] != n) parent[n] = find(parent[n]);
  return parent[n];
}
void join(int a, int b) {
  a = find(a);
  b = find(b);
  if (Rank[a] > Rank[b]) {
    parent[a] = b;
  } else if (Rank[a] < Rank[b]) {
    parent[b] = a;
  } else {
    parent[a] = b;
    Rank[b]++;
  }
}
void addToGroup(int node, int g) {
  if (group[g].count(node) == 1) return;
  seen[node] = true;
  group[g].insert(node);
  if (iscut[node]) return;
  for (int i = 0; i < adj[node].size(); i++) {
    addToGroup(adj[node][i], g);
  }
}
bool findEven(int node, int g, int p = -1) {
  seen[node] = true;
  if (group[g].count(node) == 0) return 1;
  if (parity[node] == p) return 1;
  if (parity[node] == p * -1) return 0;
  parity[node] = p;
  for (int i = 0; i < adj[node].size(); i++) {
    if (findEven(adj[node][i], g, p * -1) == 0) {
      return 0;
    }
  }
  return 1;
}
bool parityOf(int g) {
  if (isEven[g] == 0) {
    if (findEven(*group[g].begin(), g) == 1) {
      isEven[g] = 1;
    } else {
      isEven[g] = -1;
    }
    for (set<int>::iterator i = group[g].begin(); i != group[g].end(); i++) {
      parity[*i] = 0;
    }
  }
  return (isEven[g] == 1 ? 0 : 1);
}
void addToIsland(int node, int island) {
  if (seen[node]) return;
  seen[node] = true;
  islandOf[node] = island;
  for (int i = 0; i < adj[node].size(); i++) {
    addToIsland(adj[node][i], island);
  }
}
void findclusterp(int node, int cluster, int parity = -1) {
  if (false) cout << "Hi\n";
  if (seen[node] == cluster) return;
  if (evenCluster[cluster].count(node) == 0) return;
  seen[node] = cluster;
  if (false) cout << node << " " << parity << "\n";
  if (parity == 1) clusterAlpha[cluster].insert(node);
  for (int i = 0; i < adj[node].size(); i++) {
    findclusterp(adj[node][i], cluster, parity * -1);
  }
}
int main() {
  cin >> nodes >> edges;
  for (int i = 0; i < edges; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    adjset[a].insert(b);
    adjset[b].insert(a);
  }
  for (int i = 1; i <= nodes; i++) seen[i] = false;
  for (int i = 1; i <= nodes; i++) {
    if (!seen[i]) {
      addToIsland(i, i);
      findComponents(i);
    }
  }
  if (false) {
    for (int i = 1; i <= nodes; i++) {
      if (iscut[i]) cout << i << "," << low[i] << "," << depth[i] << " ";
    }
    cout << "\n";
  }
  for (int i = 1; i <= nodes; i++) parent[i] = i;
  for (int i = 1; i <= nodes; i++) {
    seen[i] = false;
  }
  for (int i = 1; i <= nodes; i++) {
    seen[i] = false;
  }
  for (int i = 0; i < counter; i++) {
    if (parityOf(i) == 0) {
      for (set<int>::iterator j = group[i].begin(); j != group[i].end(); j++) {
        evenGroupOf[*j].push_back(i);
      }
    }
  }
  for (int i = 0; i <= nodes; i++) {
    if (evenGroupOf[i].size() <= 1) continue;
    for (int j = 1; j < evenGroupOf[i].size(); j++) {
      join(evenGroupOf[i][j - 1], evenGroupOf[i][j]);
    }
  }
  for (int i = 1; i <= nodes; i++) {
    for (int j = 0; j < evenGroupOf[i].size(); i++) {
      evenClusterOf[i].insert(find(evenGroupOf[i][j]));
      evenCluster[find(evenGroupOf[i][j])].insert(i);
    }
  }
  for (int i = 0; i <= nodes; i++) seen[i] = -1;
  for (int i = 0; i <= nodes; i++) {
    if (false) cout << evenCluster[i].size() << " ";
    if (evenCluster[i].size() >= 1) {
      findclusterp(*evenCluster[i].begin(), i);
    }
  }
  if (false) {
    cout << "#groups: " << counter << "\n";
    for (int i = 0; i < counter; i++) {
      for (set<int>::iterator j = group[i].begin(); j != group[i].end(); j++) {
        cout << (*j) << " ";
      }
      cout << "(" << find(i) << ")";
      if (parityOf(i) == 0) {
        cout << "E "
             << " (";
        for (set<int>::iterator j = clusterAlpha[find(i)].begin();
             j != clusterAlpha[find(i)].end(); j++) {
          cout << *j << " ";
        }
        cout << ")";
      }
      cout << "\n";
    }
  }
  int queries;
  cin >> queries;
  for (int i = 0; i < queries; i++) {
    int a, b;
    cin >> a >> b;
    if (answercache.count(make_pair(a, b)) == 1) {
      cout << (answercache[make_pair(a, b)] ? "Yes\n" : "No\n");
      continue;
    }
    bool ans;
    if (islandOf[a] != islandOf[b]) {
      ans = 0;
    } else if (a == b) {
      ans = 0;
    } else {
      ans = 1;
      int inCommon = -1;
      for (set<int>::iterator j = evenClusterOf[a].begin();
           j != evenClusterOf[a].end(); j++) {
        if (evenClusterOf[b].count(*j) == 1) {
          ans = 0;
          inCommon = *j;
        }
      }
      if (ans == 0) {
        if (clusterAlpha[inCommon].count(a) !=
            clusterAlpha[inCommon].count(b)) {
          ans = 1;
        }
      }
    }
    answercache[make_pair(a, b)] = ans;
    cout << (ans ? "Yes\n" : "No\n");
  }
}
