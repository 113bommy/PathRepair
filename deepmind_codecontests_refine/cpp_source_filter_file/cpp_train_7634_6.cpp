#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000,100000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const long double eps = 1e-10;
const long double PI = 2 * acos(0.0);
const long double E = 2.71828;
pair<long long, long long> a[111111];
long long aa[111111];
int main(void) {
  long long n, k, b;
  cin >> n >> k >> b;
  for (int i = 0; i < n; i++)
    scanf("%I64d", &a[i].first), a[i].second = i, aa[i] = a[i].first;
  sort(a, a + n - 1);
  long long rez = 0;
  set<long long> ss;
  ss.clear();
  for (int i = n - 2; i >= n - k; i--)
    rez += a[i].first, ss.insert(a[i].second);
  long long h = a[n - k - 1].second;
  for (int i = 0; i < n - 1; i++) {
    if (ss.find(i) != ss.end()) {
      long long ans = rez + h;
      if (ans > b) cout << i + 1 << endl, exit(0);
    } else {
      long long ans = rez + aa[i];
      if (ans > b) cout << i + 1 << endl, exit(0);
    }
  }
  cout << n << endl;
  return 0;
}
