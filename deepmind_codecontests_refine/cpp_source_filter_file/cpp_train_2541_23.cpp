#include <bits/stdc++.h>
using namespace std;
mt19937_64 random_num(
    chrono::high_resolution_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const int base = 26;
int n, d;
int a[55];
bool f[500001];
int res[500001];
multiset<int> s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> d;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  int pos = 1, sum = 0;
  while (pos <= n && sum + d >= a[pos]) sum += a[pos++];
  n = --pos;
  f[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 500000; j >= a[i]; j--) f[j] = f[j - a[i]];
  for (int i = 1; i <= 500000; i++) res[i] = MOD;
  res[0] = 0;
  s.insert(0);
  int t = 0;
  for (int i = 1; i <= 500000; i++) {
    while (t + d < i) s.erase(s.find(res[t++]));
    if (f[i]) res[i] = min(res[i], (*s.begin() + 1));
    s.insert(res[i]);
  }
  for (int i = 500000; i >= 0; i--)
    if (res[i] != MOD) {
      cout << i << " " << res[i];
      return 0;
    }
}
