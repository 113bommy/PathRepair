#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e3 + 4;
struct Node {
  int la, nx;
} nodes[maxn];
int X[maxn], Y[maxn];
std::vector<int> yp[maxn];
int R, C, N, K;
int ordX[maxn], ord[maxn];
int ans[maxn], xans = 0;
inline void update(int x) {
  int c = x;
  for (int k = 1; k < K && c; ++k) c = nodes[c].nx;
  xans -= ans[x];
  if (!nodes[x].la)
    ans[x] = X[c] * (R + 1 - X[x]);
  else
    ans[x] = X[c] * (X[nodes[x].la] - X[x]);
  xans += ans[x];
}
int main() {
  cin >> R >> C >> N >> K;
  for (int i = 1; i <= N; ++i) {
    cin >> X[i] >> Y[i];
    yp[Y[i]].push_back(i);
  }
  iota(ordX + 1, ordX + N + 1, 1);
  sort(ordX + 1, ordX + N + 1, [&](int a, int b) { return X[a] > X[b]; });
  long long rans = 0;
  for (int ups = 1; ups <= C; ++ups) {
    xans = 0;
    memset(ans, 0, sizeof(ans));
    int cn = 0;
    for (int i = 1; i <= N; ++i) {
      if (Y[ordX[i]] >= ups) ord[++cn] = ordX[i];
    }
    memset(nodes, 0, sizeof(nodes));
    for (int i = 1; i <= cn; ++i) {
      nodes[ord[i]].la = ord[i - 1];
      nodes[ord[i - 1]].nx = ord[i];
    }
    for (int i = 1; i <= cn; ++i) update(ord[i]);
    rans += xans;
    for (int i = C; i > ups; --i) {
      for (int j : yp[i]) {
        nodes[nodes[j].la].nx = nodes[j].nx;
        nodes[nodes[j].nx].la = nodes[j].la;
      }
      for (int j : yp[i]) {
        for (int k = 1, c = nodes[j].la; k < K && c; ++k, c = nodes[c].la)
          update(c);
        if (nodes[j].nx) update(nodes[j].nx);
        xans -= ans[j];
      }
      rans += xans;
    }
  }
  cout << rans << endl;
  return 0;
}
