#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long n, m, b, c, k, temp, x, y, ans = 1;
const int MAXN = 1000000 + 11;
inline long long max(long long a, long long b) { return ((a > b) ? a : b); }
inline long long min(long long a, long long b) { return ((a > b) ? b : a); }
inline long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
inline vector<long long> read(int n) {
  vector<long long> v(n);
  for (int i = 0; i < v.size(); i++) cin >> v[i];
  return v;
}
int cnt[MAXN], ocnt[MAXN], a[MAXN];
void solveforthiscase(const int& test) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i], ocnt[min(a[i], 1000001)]++;
  for (int i = 1; i <= m; i++) {
    cnt[i] += ocnt[i];
    if (cnt[i] > temp) temp = cnt[i], ans = i;
    for (int j = 2 * i; j <= m; j += i) cnt[j] += ocnt[i];
  }
  cout << ans << ' ';
  vector<int> id;
  for (int i = 0; i < n; i++)
    if (ans % a[i] == 0) id.push_back(i + 1);
  cout << id.size() << '\n';
  for (auto x : id) cout << x << ' ';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start, end;
  start = clock();
  int test = 1;
  for (int i = 1; i <= test; i++) solveforthiscase(i);
  end = clock();
  long double t_t = (long double)(end - start) / (long double)(CLOCKS_PER_SEC);
  if (false) cerr << (long double)t_t * 1000 << " ms ";
}
