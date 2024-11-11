#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int rk[N], down[N], up[N], a[N];
int in[N], out[N];
int q[N], h, t;
int n, m, K;
vector<int> vec[N];
vector<int> vi[N], vo[N];
struct data {
  int w, x;
  data() {}
  data(int w, int x) : w(w), x(x) {}
  friend bool operator<(data aa, data bb) { return aa.w > bb.w; }
};
priority_queue<data> minh;
void work(int x, int now) {
  int i, y;
  rk[x] = now;
  for (i = 0; i <= (int)vi[x].size() - 1; i++) {
    y = vi[x][i];
    down[y] = max(down[y], rk[x] + 1);
    in[y]--;
    if (!in[y]) vec[down[y]].push_back(y);
  }
}
int main() {
  int i, x, y, j;
  scanf("%d%d%d", &n, &m, &K);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++)
    if (a[i])
      up[i] = a[i];
    else
      up[i] = K;
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    swap(x, y);
    out[x]++;
    vo[y].push_back(x);
    in[y]++;
    vi[x].push_back(y);
  }
  h = t = 0;
  for (i = 1; i <= n; i++)
    if (out[i] == 0) q[++t] = i;
  while (h < t) {
    x = q[++h];
    for (i = 0; i <= (int)vo[x].size() - 1; i++) {
      y = vo[x][i];
      out[y]--;
      up[y] = min(up[y], up[x] - 1);
      if (!out[y]) q[++t] = y;
    }
  }
  for (i = 1; i <= n; i++)
    if (a[i] && up[i] < a[i]) {
      printf("-1\n");
      return 0;
    }
  for (i = 1; i <= n; i++)
    if (up[i] < 1) {
      printf("-1\n");
      return 0;
    }
  for (i = 1; i <= n; i++)
    if (a[i])
      down[i] = a[i];
    else
      down[i] = 1;
  for (i = 1; i <= n; i++)
    if (!in[i]) vec[down[i]].push_back(i);
  for (i = 1; i <= K; i++) {
    for (j = 0; j <= (int)vec[i].size() - 1; j++) {
      x = vec[i][j];
      minh.push(data(up[x], x));
    }
    if (minh.empty()) {
      printf("-1\n");
      return 0;
    }
    work(minh.top().x, i);
    minh.pop();
    while (!minh.empty() && minh.top().w == i) {
      work(minh.top().x, i);
      minh.pop();
    }
  }
  for (i = 1; i <= n; i++) printf("%d ", rk[i]);
}
