#include <bits/stdc++.h>
using namespace std;
void reader() {}
void IOFast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(3);
  long long x;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    a[x]++;
  }
  if (a[1] == 0 || a[2] == 0) {
    if (a[2]) {
      for (long long i = 0; i < n; i++) cout << 2 << " ";
    }
    if (a[1]) {
      for (long long i = 0; i < n; i++) cout << 1 << " ";
    }
    cout << endl;
    return;
  }
  if (a[1] < 3) {
    cout << 1 << " " << 2 << " ";
    a[1]--;
    a[2]--;
  } else {
    cout << 1 << " " << 1 << " " << 1 << " ";
    a[1] -= 3;
  }
  while (a[2]--) cout << 2 << " ";
  while (a[1]--) cout << 1 << " ";
  cout << "\n";
}
signed main() {
  reader();
  IOFast();
  long long t = 1;
  while (t--) solve();
  return 0;
}
