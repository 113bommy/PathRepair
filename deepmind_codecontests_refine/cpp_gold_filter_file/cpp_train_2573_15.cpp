#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 100;
const long long inf = 1e18 + 100;
long double EPS = 1e-18;
const int INF = 2000000000;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dxx[] = {0, 0, -1, -1, -1, 1, 1, 1};
int dyy[] = {1, -1, 0, 1, -1, 0, 1, -1};
bool valid(int x, int y, int nn, int mm) {
  return (x >= 0 && y >= 0 && x < nn && y < mm);
}
long long fastpow(long long a, long long b) {
  if (!b) return 1;
  if (b % 2) return (a * fastpow(a, b - 1)) % mod;
  return fastpow((a * a) % mod, b / 2) % mod;
}
long long divv(long long a, long long b) {
  return (a % mod) * (fastpow(b, mod - 2) % mod);
}
int n, m;
bool com(pair<int, int> a, pair<int, int> b) {
  return (a.first % m) < (b.first % m);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n >> m;
  int x = n / m;
  pair<int, int> arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i].first, arr[i].second = i;
  sort(arr, arr + n, com);
  long long ans[n], cn = 0, ii = 0, jj = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < x; j++) {
      if (arr[ii].first % m != i) {
        if (arr[ii].first % m > i) {
          int temp = m - (arr[n - 1 - jj].first % m) + i;
          arr[n - 1 - jj].first += temp, cn += temp;
          jj++;
        } else {
          int temp = i - (arr[ii].first % m);
          arr[ii].first += temp, cn += temp;
          ii++;
        }
      } else
        ii++;
    }
  }
  cout << cn << endl;
  for (int i = 0; i < n; i++) ans[arr[i].second] = arr[i].first;
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  return 0;
}
