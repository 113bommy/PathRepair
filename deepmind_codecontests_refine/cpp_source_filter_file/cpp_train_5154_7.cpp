#include <bits/stdc++.h>
using namespace std;
static int const inf = 100100;
static inline void init_buffer(int *const buffer) {
  for (int j = 0; j < 10; ++j) {
    buffer[j] = inf;
  }
}
struct Node {
  int people[10];
  int links[18];
  int mins[18][10];
  int dist;
  Node() {
    init_buffer(people);
    for (int i = 0; i < 18; ++i) {
      links[i] = 1;
      for (int j = 0; j < 10; ++j) {
        mins[i][j] = inf;
      }
    }
  }
  void add_person(int person) {
    for (int i = 0; i < 10; ++i) {
      if (person < people[i]) {
        swap(person, people[i]);
      }
    }
  }
};
static Node nodes[100100];
static vector<int> tree[100100];
static inline void init_buffer(int *const buffer, int v) {
  Node const &node = nodes[v];
  for (int j = 0; j < 10; ++j) {
    buffer[j] = node.people[j];
  }
}
static inline void init_buffer(int *const buffer, int const *const src) {
  for (int j = 0; j < 10; ++j) {
    buffer[j] = src[j];
  }
}
static inline void merge(int const *a, int const *b, int *const dst) {
  for (int i = 0; i < 10; ++i) {
    if (*a < *b) {
      dst[i] = *a;
      ++a;
    } else {
      if (*a == *b) {
        ++a;
      }
      dst[i] = *b;
      ++b;
    }
  }
}
static inline void dfs(int const n, int const p, int const dist) {
  Node &node = nodes[n];
  node.links[0] = p;
  merge(node.people, nodes[p].people, node.mins[0]);
  for (int i = 1; i < 18; ++i) {
    Node const &halfway_node = nodes[node.links[i - 1]];
    node.links[i] = halfway_node.links[i - 1];
    merge(node.mins[i - 1], halfway_node.mins[i - 1], node.mins[i]);
  }
  node.dist = dist;
  size_t const numof_children = tree[n].size();
  for (size_t i = 0; i < numof_children; ++i) {
    int const child = tree[n][i];
    if (child != p) {
      dfs(child, n, dist + 1);
    }
  }
}
static inline void step(int &u, int *const buffer, int i) {
  int tmp_buffer[10];
  init_buffer(tmp_buffer, buffer);
  Node const &node = nodes[u];
  merge(node.mins[i], tmp_buffer, buffer);
  u = node.links[i];
}
static inline void walk(int &u, int *const buffer, int diff) {
  int i = 0;
  while (diff) {
    if (diff & 1) {
      step(u, buffer, i);
    }
    diff /= 2;
    ++i;
  }
}
static inline void query(int u, int v, int *const buffer) {
  if (nodes[u].dist < nodes[v].dist) {
    swap(u, v);
  }
  int const diff = nodes[u].dist - nodes[v].dist;
  int u_buffer[10];
  int v_buffer[10];
  init_buffer(u_buffer, u);
  init_buffer(v_buffer, v);
  walk(u, u_buffer, diff);
  if (u == v) {
    init_buffer(buffer, u_buffer);
    return;
  }
  for (int i = 17; i > 0; --i) {
    if (nodes[u].links[i] != nodes[v].links[i]) {
      step(u, u_buffer, i);
      step(v, v_buffer, i);
    }
  }
  step(u, u_buffer, 0);
  step(v, v_buffer, 0);
  merge(u_buffer, v_buffer, buffer);
}
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  for (int i = 1, c; i <= m; ++i) {
    scanf("%d", &c);
    nodes[c].add_person(i);
  }
  dfs(1, 1, 0);
  int buffer[10];
  for (int i = 0, u, v, a; i < q; ++i) {
    scanf("%d%d%d", &u, &v, &a);
    init_buffer(buffer);
    query(u, v, buffer);
    int x = 0;
    for (; x < 10; ++x) {
      if (buffer[x] == inf) {
        break;
      }
    }
    int const k = min(x, a);
    printf("%d", k);
    for (int j = 0; j < k; ++j) {
      printf(" %d", buffer[j]);
    }
    printf("\n");
  }
  return 0;
}
