#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 60;
bool check(long long a[], long long n) {
  for (long long int i = 1; i < n; ++i)
    if (a[i] < a[i - 1]) return false;
  return true;
}
bool check1(long long a[], long long n) {
  for (long long int i = 1; i < n; ++i)
    if (a[i] > a[i - 1]) return false;
  return true;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  set<long long, greater<long long> > s;
  for (long long int i = 0; i < n; ++i) {
    cin >> a[i];
    s.insert(a[i]);
  }
  if (s.size() < 2 || n < 3) {
    cout << -1 << endl;
    return;
  }
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = i + 1; j < n; ++j) {
      if (a[j] != a[i]) {
        swap(a[j], a[i]);
        if (!check(a, n) && !check1(a, n)) {
          cout << i << " " << j << endl;
          return;
        }
        swap(a[j], a[i]);
      }
    }
  }
  cout << -1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
