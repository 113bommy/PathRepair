#include <bits/stdc++.h>
using namespace std;
const unsigned int mod = 1e7 + 7;
const long long int N = 1e5;
bool visit[100009] = {false};
long long int ans;
vector<long long int> v[100009];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int l, n, x = 0, p, q, y, m, lo[2009], ans = 0, sum = 0,
                      k = INT_MAX, t = 2, z = 0, w = 0, pre = 1e5, mid,
                      h[49] = {0}, a[4000] = {0}, t1 = 0, t2, now, r = 0, i = 0,
                      j = 0, flag = 0, temp = 0, e = 1e4, o = 0;
  cin >> n >> k;
  if (n == 1) return cout << 0, 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (a[j] - a[i] <= k) {
        x = j - i + 1;
      }
    }
    ans = max(ans, x);
  }
  cout << n - ans;
  return 0;
}
