#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n;
  cin >> n;
  int t[n];
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    t[i]--;
  }
  int ans[n];
  for (int i = 0; i < n; i++) ans[i] = 0;
  for (int i = 0; i < n; i++) {
    int c[n];
    for (int j = 0; j < n; j++) {
      c[j] = 0;
    }
    int cm = 0;
    int cc = -1;
    for (int j = i; j < n; j++) {
      c[t[j]]++;
      if (c[t[j]] > cm) {
        cc = t[j];
        cm = c[t[j]];
      } else if (c[t[j]] == cm) {
        if (t[j] < t[cc]) {
          cc = t[j];
          cm = c[t[j]];
        }
      }
      ans[cc]++;
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  return 0;
}
int main() { solve(); }
