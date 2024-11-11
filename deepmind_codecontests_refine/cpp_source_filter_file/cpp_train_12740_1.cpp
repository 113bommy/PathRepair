#include <bits/stdc++.h>
using namespace std;
int DEBUG = 0;
vector<int> edge[100010];
int depth[100010];
int main(int argc, char **argv) {
  DEBUG = (argc >= 2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  memset(depth, 0, sizeof(depth));
  depth[0] = 1;
  deque<int> que;
  que.push_back(0);
  while (!que.empty()) {
    int top = que.front();
    que.pop_front();
    for (int i = 0; i < int(edge[top].size()); i++) {
      int nxt = edge[top][i];
      if (depth[nxt] == 0) {
        depth[nxt] = depth[top] + 1;
        que.push_back(nxt);
      }
    }
  }
  if (DEBUG) {
    for (int i = 0; i < n; i++) {
      printf("depth[%d]= %d\n", i, depth[i]);
    }
  }
  double expval = 0.0;
  for (int i = 0; i < n; i++) {
    expval += 1.0 / double(depth[i]);
  }
  printf("%.20f\n", expval);
  return 0;
}
