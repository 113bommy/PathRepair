#include <bits/stdc++.h>
using namespace std;
inline void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long maxn = 2e5 + 123;
const long long inf = 1e9 + 123;
const long long linf = 1e18 + 123;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double pi = acos(-1);
int dx[8] = {0, 1, -1, 0, 1, -1, 1, -1};
int dy[8] = {1, 0, 0, -1, 1, 1, -1, -1};
int dist[maxn], last[maxn], blocksize = 320, a[maxn];
int main() {
  boost();
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i + a[i] >= n) {
      dist[i] = 1;
      last[i] = i;
    } else if ((i + a[i]) / blocksize != i / blocksize) {
      dist[i] = 1;
      last[i] = i + a[i];
    } else {
      dist[i] = dist[i + a[i]] + 1;
      last[i] = last[i + a[i]];
    }
  }
  while (q--) {
    int type, i;
    cin >> type >> i;
    i--;
    if (type == 1) {
      int ans = 0;
      while (1 == 1) {
        ans += dist[i];
        if (last[i] == i) {
          break;
        }
        if ((last[i]) / blocksize == i / blocksize) {
          ans--;
        }
        i = last[i];
      }
      cout << i + 1 << " " << ans << "\n";
    } else {
      int x;
      cin >> x;
      a[i] = x;
      for (int j = i; j >= 0; j--) {
        if (j / blocksize != i / blocksize) {
          break;
        }
        if (j + a[j] >= n) {
          dist[j] = 1;
          last[j] = i;
        } else if ((j + a[j]) / blocksize != j / blocksize) {
          dist[j] = 1;
          last[j] = j + a[j];
        } else {
          dist[j] = dist[j + a[j]] + 1;
          last[j] = last[j + a[j]];
        }
      }
    }
  }
  exit(0);
}
