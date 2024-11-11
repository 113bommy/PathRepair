#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
const long long inf = -1e10;
const long long N = 2e6 + 10;
long long a[N];
unordered_set<long long> prime;
bool p[N];
void filler() {
  memset(p, false, sizeof(p));
  for (long long i = 2; i * i < N; i++) {
    if (p[i] == false)
      for (long long j = i * i; j < N; j += i) {
        p[j] = true;
      }
  }
  for (long long i = 2; i < N; i++)
    if (!p[i]) prime.insert(i);
}
bool check(long long n, long long x) {
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (prime.find(a[i] + a[j]) != prime.end()) {
        if (x < 2) {
          cout << 2 << endl;
          cout << a[i] << " " << a[j] << endl;
          return true;
        }
      }
    }
  }
  if (x == 0) {
    cout << 1 << endl << a[0] << endl;
    return true;
  }
  return false;
}
void go() {
  long long n;
  cin >> n;
  filler();
  for (long long i = 0; i < n; i++) cin >> a[i];
  if (n == 2) {
    long long sum = 0;
    for (long long i = 0; i < 2; i++) sum += a[i];
    if (prime.find(sum) != prime.end()) {
      cout << 2 << endl;
      cout << a[0] << " " << a[1] << endl;
      return;
    }
    cout << 1 << endl;
    cout << a[0] << endl;
    return;
  }
  if (n == 1) {
    cout << 1 << endl;
    cout << a[0] << endl;
    return;
  }
  long long cnt = 0, z = 0, val;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 1) cnt++;
    if (prime.find(a[i] + 1) != prime.end() && a[i] != 1) z = 1, val = a[i];
  }
  if (check(n, cnt + z)) return;
  cout << cnt + z << endl;
  for (long long i = 0; i < cnt; i++) cout << 1 << " ";
  if (z) cout << val << endl;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t = 1;
  cout << fixed << setprecision(12);
  while (t--) {
    go();
  }
}
