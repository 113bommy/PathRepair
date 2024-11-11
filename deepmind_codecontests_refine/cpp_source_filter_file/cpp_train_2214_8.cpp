#include <bits/stdc++.h>
using namespace std;
long long m_pow(long long a, long long b, long long M = 1000000007) {
  long long res = 1;
  for (; b; b >>= 1, a = (a * a) % M)
    if (b & 1) res = (res * a) % M;
  return res;
}
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); };
double dis(pair<int, int> a, pair<int, int> b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
              (a.second - b.second) * (a.second - b.second));
}
int dr[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dc[] = {1, 0, -1, 0, 1, -1, 1, -1};
int n, m, k, t;
string ansok[2] = {"NO", "YES"};
int a[200001];
long long ps[3001][3001];
int main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cin >> t;
  while (t--) {
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      for (int j = 0; j < n; j++) {
        ps[i][j] = ps[i - 1][j];
      }
      ps[i][--a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++)
        ans += ps[j - 1][a[j]] * (ps[n][a[j]] - ps[i][a[j]]);
    }
    cout << ans << '\n';
  }
  return 0;
}
