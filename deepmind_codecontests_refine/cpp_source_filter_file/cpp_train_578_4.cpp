#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11, mod = 1e9 + 7;
const int MAX = 1e9 + 11;
const int INF1 = 2e9 + 11;
const long long INF2 = 2e18 + 11;
const int base = 500;
const int P = 31;
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
const double EPS = 1e-12;
const double PI = acos(-1.0);
int n, l, r, a[N], b[N];
int main() {
  if (fopen("peacefulsets"
            ".in",
            "r"))
    freopen(
        "peacefulsets"
        ".in",
        "r", stdin),
        freopen(
            "peacefulsets"
            ".out",
            "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i += 1) cin >> a[i];
  for (int i = 1; i <= n; i += 1) cin >> b[i];
  vector<int> v, v2, vec1, vec2;
  for (int i = 1; i <= l - 1; i += 1)
    vec1.emplace_back(a[i]), vec2.emplace_back(b[i]);
  for (int i = r + 1; i <= n; i += 1)
    vec1.emplace_back(a[i]), vec2.emplace_back(a[i]);
  for (int i = l; i <= r; i += 1) v.emplace_back(a[i]), v2.emplace_back(b[i]);
  sort(v.begin(), v.end());
  sort(v2.begin(), v2.end());
  cout << (v == v2 && vec1 == vec2 ? "TRUTH" : "LIE");
  return 0;
}
