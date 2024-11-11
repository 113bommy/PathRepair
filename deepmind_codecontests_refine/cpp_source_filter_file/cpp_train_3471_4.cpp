#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const long double pi = acos(-1);
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int a[1000000], c[1000000];
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  cout << fixed;
  cout.tie(0);
  cin.tie(0);
  int n, k;
  long long b;
  long long tot = 0;
  cin >> n >> k >> b;
  map<int, int> m;
  for (int(i) = 0; (i) < (n); (i)++) {
    cin >> a[i];
    c[i] = a[i];
  }
  sort(c, c + n - 1);
  for (int i = n - 2, k1 = k; i >= 0 && k1 >= 2; k1--, i--)
    tot += c[i], m[c[i]] = 1;
  for (int i = 0; i < n - 1; i++) {
    if (m[a[i]]) {
      long long tt = tot - a[i] + c[n - k];
      if (b - tt < a[i]) {
        cout << i + 1 << '\n';
        return 0;
      }
    } else {
      if (b - tot < a[i]) {
        cout << i + 1 << '\n';
        return 0;
      }
    }
  }
  cout << n << '\n';
  return 0;
}
