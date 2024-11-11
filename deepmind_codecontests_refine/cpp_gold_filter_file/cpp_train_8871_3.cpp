#include <bits/stdc++.h>
using namespace std;
void get_rodering(stack<int> *st);
void BFS(stack<int> *st);
int edges[3010][3010], path[3010], rodering[3010];
bool visited[3010];
int main() {
  int nodes = 0, a = 0, b = 0;
  scanf("%d", &nodes);
  for (int i = 1; i <= nodes; i++) {
    scanf("%d %d", &a, &b);
    edges[a][edges[a][0] + 1] = b;
    edges[b][edges[b][0] + 1] = a;
    edges[a][0]++;
    edges[b][0]++;
  }
  stack<int> st;
  st.push(1);
  visited[1] = true;
  memset(rodering, -1, sizeof(rodering));
  get_rodering(&st);
  BFS(&st);
  printf("%d", rodering[1]);
  for (int i = 2; i <= nodes; i++) {
    printf(" %d", rodering[i]);
  }
  putchar('\n');
  return 0;
}
void get_rodering(stack<int> *st) {
  bool end = false;
  while (!end) {
    int node = st->top();
    visited[node] = true;
    st->pop();
    for (int i = 1; i <= edges[node][0]; i++) {
      if (visited[edges[node][i]] && edges[node][i] != path[node]) {
        while (st->size() != 0) {
          (*st).pop();
        }
        int moving_node = node;
        while (moving_node != edges[node][i]) {
          rodering[moving_node] = 0;
          st->push(moving_node);
          moving_node = path[moving_node];
        }
        rodering[moving_node] = 0;
        st->push(moving_node);
        end = true;
        break;
      } else if (!visited[edges[node][i]]) {
        (*st).push(edges[node][i]);
        path[edges[node][i]] = node;
      }
    }
  }
  return;
}
void BFS(stack<int> *st) {
  while (!st->empty()) {
    int node = st->top();
    st->pop();
    for (int i = 1; i <= edges[node][0]; i++) {
      if (rodering[edges[node][i]] >= 0) {
        continue;
      } else {
        rodering[edges[node][i]] = rodering[node] + 1;
        st->push(edges[node][i]);
      }
    }
  }
}
