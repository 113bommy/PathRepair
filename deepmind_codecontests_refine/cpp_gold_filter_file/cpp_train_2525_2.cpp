#include <bits/stdc++.h>
using namespace std;
long long n, k, l, rez;
void solve() {
  rez = 1;
  cin >> n >> k >> l;
  long long tec = 1000000000001, h = -1;
  vector<long long> m(n);
  vector<long long> safe(n, 0);
  for (long long j = 0; j < n; ++j) {
    cin >> m[j];
    if (m[j] + k <= l) {
      safe[j] = -1;
    } else if (m[j] > l) {
      rez = 0;
    } else {
      safe[j] = l - m[j];
    }
    if (safe[j] == -1) {
      tec = 10000000000001;
      h = -1;
    } else if (h == -1) {
      tec = min((tec + h), safe[j]);
      if (tec == 0) {
        h = 1;
      }
    } else {
      tec++;
      if (tec > safe[j]) {
        rez = 0;
      }
    }
  }
  if (rez == 0) {
    cout << "No"
         << "\n";
  } else {
    cout << "Yes"
         << "\n";
  }
}
int main() {
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
}
