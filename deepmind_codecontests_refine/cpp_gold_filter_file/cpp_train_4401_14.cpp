#include <bits/stdc++.h>
using namespace std;
int64_t TN = 1;
void solve() {
  int64_t n;
  cin >> n;
  int64_t a[n];
  map<int64_t, int64_t> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    m[a[i]]++;
  }
  if (m[a[0]] == n) {
    cout << n << endl;
  } else {
    cout << 1 << endl;
  }
}
int main() {
  cin >> TN;
  for (int i = 0; i < TN; ++i) {
    solve();
  }
  return 0;
}
