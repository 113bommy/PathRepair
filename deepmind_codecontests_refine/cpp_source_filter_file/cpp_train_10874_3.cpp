#include <bits/stdc++.h>
const int MAXN = 1e5 * 5;
const int INF = 1e9 + 7;
using namespace std;
int n, h;
int a[MAXN];
void add(int &a, int b) {
  a += b;
  if (a >= INF) a -= INF;
}
int f[2001][2001];
int duyet(int i, int c) {
  if (f[i][c] > -1) return f[i][c];
  if (i > n) return c == 0;
  int ans = 0;
  int cur = a[i] + c;
  if (cur < h - 1 || cur > h) return 0;
  if (cur == h) {
    add(ans, duyet(i + 1, c));
    if (c) add(ans, (1LL * duyet(i + 1, c - 1) * c) % INF);
  }
  if (cur == h - 1) {
    add(ans, (1LL * duyet(i + 1, c) * (c + 1)) % INF);
    add(ans, duyet(i + 1, c + 1));
  }
  f[i][c] = ans;
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> h;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(f, -1, sizeof(f));
  cout << duyet(1, 0) << endl;
  return 0;
}
