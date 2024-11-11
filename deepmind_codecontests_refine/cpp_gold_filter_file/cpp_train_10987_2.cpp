#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> edge[105][105];
vector<uint64_t> graph_hash[105];
void Clear() {
  n = k = 0;
  for (int i = 0; i < 105; ++i) {
    graph_hash[i].clear();
    for (int j = 0; j < 105; ++j) {
      edge[i][j].clear();
    }
  }
}
int GetChildren(bool *marked, vector<int> &nodes, int *father, int *children,
                const vector<int> *edge2, int node_id) {
  nodes.push_back(node_id);
  marked[node_id] = true;
  children[node_id] = 1;
  for (int i = 0; i < edge2[node_id].size(); ++i) {
    int t = edge2[node_id][i];
    if (marked[t]) continue;
    int c = GetChildren(marked, nodes, father, children, edge2, t);
    father[t] = node_id;
    children[node_id] += c;
  }
  return children[node_id];
}
uint64_t seed = 1000003;
uint64_t Hash(bool *marked, const vector<int> &allnodes,
              const vector<int> *edge2, int root) {
  vector<uint64_t> children;
  marked[root] = true;
  for (int i = 0; i < edge2[root].size(); ++i) {
    int t = edge2[root][i];
    if (marked[t]) continue;
    children.push_back(Hash(marked, allnodes, edge2, t));
  }
  if (children.size()) {
    sort(children.begin(), children.end());
  }
  uint64_t v = 1;
  for (int i = 0; i < children.size(); ++i) {
    v = (v + v ^ children[i]) * seed;
  }
  return v;
}
uint64_t CalculateHash(bool *marked, const vector<int> *edge2, int node_id,
                       int disable) {
  int children[101] = {0};
  memset(children, 0, sizeof(children));
  vector<int> root_node;
  vector<int> nodes;
  int father[101] = {0};
  memset(father, -1, sizeof(father));
  GetChildren(marked, nodes, father, children, edge2, node_id);
  int min_child_tree = 1 << 20;
  if (nodes.size() == 1) {
    return 1;
  }
  for (int i = 0; i < nodes.size(); ++i) {
    int s = nodes[i];
    int max_c = -1;
    for (int j = 0; j < edge2[s].size(); ++j) {
      int t = edge2[s][j];
      if (father[t] != s) continue;
      int c = children[t];
      if (max_c < c) {
        max_c = c;
      }
    }
    if (nodes.size() - children[s]) {
      int c = nodes.size() - children[s];
      if (max_c < c) {
        max_c = c;
      }
    }
    if (max_c == min_child_tree) {
      root_node.push_back(s);
    } else if (max_c < min_child_tree) {
      min_child_tree = max_c;
      root_node.clear();
      root_node.push_back(s);
    }
  }
  bool marked2[101];
  memset(marked2, 0, sizeof(marked2));
  if (disable >= 0) {
    marked2[disable] = true;
  }
  if (root_node.size() == 1) {
    return Hash(marked2, nodes, edge2, root_node[0]);
  } else {
    uint64_t ret1 = Hash(marked2, nodes, edge2, root_node[0]);
    memset(marked2, 0, sizeof(marked2));
    if (disable >= 0) {
      marked2[disable] = true;
    }
    uint64_t ret2 = Hash(marked2, nodes, edge2, root_node[1]);
    return (ret1 + ret2) * seed;
  }
}
vector<uint64_t> TreeHash(const vector<int> *edge2, int disable) {
  vector<uint64_t> ret;
  bool marked[101];
  memset(marked, 0, sizeof(marked));
  if (disable >= 0) {
    marked[disable] = true;
    ret.push_back(1);
  }
  for (int i = 0; i < n; ++i) {
    if (!marked[i]) {
      ret.push_back(CalculateHash(marked, edge2, i, disable));
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}
bool VecEqual(const vector<uint64_t> &a, const vector<uint64_t> &b) {
  if (a.size() != b.size()) return false;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}
void PrintGraph(vector<int> *edge) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < edge[i].size(); ++j) {
      if (i < edge[i][j]) {
        printf("%d %d\n", i + 1, edge[i][j] + 1);
      }
    }
  }
}
void Debug(int line) {
  return;
  printf("line: %d\n", line);
}
int main() {
  int z;
  scanf("%d", &z);
  Debug(171);
  while (z--) {
    Clear();
    scanf("%d%d", &n, &k);
    int id = -1, leaf = -1;
    for (int i = 0; i < k; ++i) {
      int m;
      scanf("%d", &m);
      if (m == n - 2) {
        id = i;
      }
      for (int j = 0; j < m; ++j) {
        int s, t;
        scanf("%d%d", &s, &t);
        s--;
        t--;
        Debug(187);
        edge[i][s].push_back(t);
        edge[i][t].push_back(s);
        Debug(190);
      }
    }
    if (id == -1) {
      printf("NO\n");
      continue;
    }
    for (int i = 0; i < n; ++i) {
      if (edge[id][i].size() == 0) {
        leaf = i;
        break;
      }
    }
    Debug(203);
    for (int i = 0; i < k; ++i) {
      graph_hash[i] = TreeHash(edge[i], -1);
    }
    Debug(211);
    for (int j = 0; j < n; ++j) {
      if (j == leaf) {
        continue;
      }
      edge[id][j].push_back(leaf);
      edge[id][leaf].push_back(j);
      bool matched[101] = {0};
      memset(matched, 0, sizeof(matched));
      int all_match = 0;
      for (int disable = 0; disable < n; ++disable) {
        vector<uint64_t> ret = TreeHash(edge[id], disable);
        bool has_match = false;
        for (int i = 0; i < k; ++i) {
          if (matched[i] == 0 && VecEqual(graph_hash[i], ret)) {
            matched[i] = 1;
            all_match++;
            has_match = true;
            break;
          }
        }
        if (has_match == false) {
          break;
        }
      }
      if (all_match == k) {
        printf("YES\n");
        PrintGraph(edge[id]);
        goto next_case;
      }
      edge[id][j].pop_back();
      edge[id][leaf].pop_back();
    }
    printf("NO\n");
  next_case:;
  }
  return 0;
}
