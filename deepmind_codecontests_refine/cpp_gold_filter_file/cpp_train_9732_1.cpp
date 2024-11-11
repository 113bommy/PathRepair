#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int src, dest, state;
};
class Solution {
 public:
  struct EdgeListNode {
    int next, dest, state, index;
  };
  struct VertexStat {
    int dist, num, last_index, last_vertex;
  };
  vector<Edge> GetPlan(int n, int m, vector<Edge> &edges) {
    vector<EdgeListNode> edge_list;
    EdgeListNode null_node;
    edge_list.push_back(null_node);
    vector<int> vertex_first_edge(n + 1);
    vector<VertexStat> vertex_state;
    VertexStat null_vertex;
    vertex_state.push_back(null_vertex);
    for (int i = 1; i <= n; i++) {
      vertex_first_edge[i] = 0;
      VertexStat temp;
      temp.dist = n + 1;
      temp.num = n + 1;
      vertex_state.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
      EdgeListNode temp;
      temp.dest = edges[i].dest;
      temp.state = edges[i].state;
      temp.index = i;
      temp.next = vertex_first_edge[edges[i].src];
      vertex_first_edge[edges[i].src] = edge_list.size();
      edge_list.push_back(temp);
      temp.dest = edges[i].src;
      temp.state = edges[i].state;
      temp.index = i;
      temp.next = vertex_first_edge[edges[i].dest];
      vertex_first_edge[edges[i].dest] = edge_list.size();
      edge_list.push_back(temp);
    }
    vertex_state[n].dist = 0;
    vertex_state[n].num = 0;
    queue<int> wait_list;
    wait_list.push(n);
    while (wait_list.size() != 0) {
      if (wait_list.front() == 1) {
        break;
      }
      int temp = wait_list.front();
      wait_list.pop();
      for (int i = vertex_first_edge[temp]; i != 0; i = edge_list[i].next)
        if ((vertex_state[temp].dist + 1 <
             vertex_state[edge_list[i].dest].dist) ||
            ((vertex_state[temp].dist + 1 ==
              vertex_state[edge_list[i].dest].dist) &&
             (vertex_state[temp].num < vertex_state[edge_list[i].dest].num))) {
          if (vertex_state[edge_list[i].dest].dist > n) {
            wait_list.push(edge_list[i].dest);
          }
          vertex_state[edge_list[i].dest].dist = vertex_state[temp].dist + 1;
          vertex_state[edge_list[i].dest].num =
              vertex_state[temp].num + (edge_list[i].state == 1 ? 0 : 1);
          vertex_state[edge_list[i].dest].last_vertex = temp;
          vertex_state[edge_list[i].dest].last_index = edge_list[i].index;
        }
    }
    vector<Edge> ans;
    for (int i = 1; i != n; i = vertex_state[i].last_vertex) {
      if (edges[vertex_state[i].last_index].state == 0) {
        Edge temp = edges[vertex_state[i].last_index];
        temp.state = 1;
        ans.push_back(temp);
      }
      edges[vertex_state[i].last_index].state = -1;
    }
    for (int i = 0; i < m; i++)
      if (edges[i].state == 1) {
        Edge temp = edges[i];
        temp.state = 0;
        ans.push_back(temp);
      }
    return ans;
  }
};
int main() {
  int n, m;
  vector<Edge> edges;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    Edge temp;
    scanf("%d%d%d", &temp.src, &temp.dest, &temp.state);
    edges.push_back(temp);
  }
  Solution aa;
  vector<Edge> ans = aa.GetPlan(n, m, edges);
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d %d\n", ans[i].src, ans[i].dest, ans[i].state);
  }
  return 0;
}
