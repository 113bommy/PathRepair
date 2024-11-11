#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int Read() {
  char c;
  c = getchar();
  int tsqua = 0;
  while (c != ' ' && c != '\n') {
    tsqua = (((tsqua << 1) << 1) << 1) + (tsqua << 1) + (int)(c - '0');
    c = getchar();
  }
  return tsqua;
}
int n, m, k;
int a[1000010];
int ans1, ans2;
vector<int> E[1000010];
int Pig(int x) {
  a[x] = 1;
  for (int i = 0; i < E[x].size(); i++)
    if (!a[E[x][i]]) a[x] += E[x][i];
  return a[x];
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  for (int i = 0; i < n; i++)
    if (!a[i]) ans2 += min(k, Pig(i)), ans1++;
  if (k == 1)
    cout << max(ans1 - 1 - 1, 0);
  else if (ans1 == 1)
    cout << 0;
  else
    cout << max(ans1 - 1 - ans2 / 2, 0);
  return 0;
}
