#include <bits/stdc++.h>
using namespace std;
struct Y {
  int v, r, idx;
};
struct X {
  int x, y;
};
int O[1000001];
Y T[100001];
X S[1000001];
bool f[1000001], ok;
inline bool inside(int i, int mid) {
  double L;
  L = sqrt(S[i].y * S[i].y + (S[i].x - T[mid].v) * (S[i].x - T[mid].v));
  if (L <= T[mid].r)
    return true;
  else
    return false;
}
int first(Y a, Y b) { return a.v < b.v; }
int main(int argc, char *argv[]) {
  int n, m, i, low, high, mid, mini, ans = 0;
  cin >> n;
  for (i = 0; i <= n - 1; i++) {
    cin >> T[i].v >> T[i].r;
    T[i].idx = i;
    O[i] = 1000000;
  }
  cin >> m;
  for (i = 1; i <= m; i++) {
    cin >> S[i].x >> S[i].y;
  }
  sort(T, T + n, first);
  for (i = 1; i <= m; i++) {
    low = 0;
    high = n - 1;
    while (low <= high) {
      mid = (low + high) / 2;
      if (S[i].x < T[mid].v - T[mid].r)
        high = mid - 1;
      else
        low = mid + 1;
      if (inside(i, mid)) {
        f[mid] = true;
        if (i < O[T[mid].idx]) O[T[mid].idx] = i;
      }
    }
  }
  for (i = 0; i <= n - 1; i++)
    if (f[i]) ans++;
  cout << ans << endl;
  for (i = 0; i <= n - 1; i++)
    if (O[i] != 1000000)
      cout << O[i] << " ";
    else
      cout << -1 << " ";
  cout << endl;
  return 0;
}
