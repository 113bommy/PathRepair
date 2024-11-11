#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long modFact(long long n, long long p) {
  if (n >= p) return 0;
  long long result = 1;
  for (long long i = 1; i <= n; i++) result = (result * i) % p;
  return result;
}
long long modPower(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void printArr(vector<long long> arr) {
  for (auto &x : arr) cout << x << " ";
  cout << '\n';
}
long long get() {
  long long temp;
  cin >> temp;
  return temp;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (auto &x : a) cin >> x;
  if (n % 2 == 0) {
    cout << "YES\n";
    return;
  } else {
    bool isSorted = true;
    for (long long i = 0; i < n - 1; i++) {
      if (a[i] >= a[i + 1]) {
        isSorted = false;
        break;
      }
    }
    if (!isSorted)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  long long t = 0;
  cin >> t;
  while (t--) solve();
  return 0;
}
