#include <bits/stdc++.h>
using namespace std;
set<int> s;
void primes() {
  int n = 1000000;
  s.insert(2);
  for (int i = 3; i < n; i++) {
    bool isprime = true;
    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        if (s.find(j) != s.end()) {
          isprime = false;
          break;
        }
      }
    }
    if (isprime) {
      s.insert(i);
    }
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int cnt = 0;
  bool dec = false;
  bool inc = false;
  int first = v[0];
  for (int i = 0; i < n - 1; i++) {
    if (v[i] <= v[i + 1]) {
      if (dec) {
        if (v[i] <= first and v[n - 1] <= first) {
          cnt++;
        } else {
          cout << "-1";
          return;
        }
      }
      inc = true;
    } else {
      if (!dec) {
        dec = true;
        if (v[i + 1] <= first)
          cnt++;
        else {
          cout << "-1";
          return;
        }
      } else {
        cout << "-1";
        return;
      }
    }
  }
  cout << cnt;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
