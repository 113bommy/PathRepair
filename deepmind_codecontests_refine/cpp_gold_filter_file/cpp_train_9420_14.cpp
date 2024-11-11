#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
pair<int, int> v[100100];
int suff[100100], oc[100100][205];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i].first;
  for (int i = 0; i < n; i++) cin >> v[i].second;
  sort(v, v + n);
  suff[n] = 0;
  for (int i = (n - 1); i >= 0; i--) suff[i] = suff[i + 1] + v[i].second;
  memset(oc, 0, sizeof(oc));
  int c = 1, ans = 1000000000;
  oc[0][v[0].second] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 201; j++) oc[i][j] = oc[i - 1][j];
    oc[i][v[i].second]++;
    if (v[i].first == v[i - 1].first) {
      c++;
      continue;
    }
    int r = max(0, (i)-2 * c + 1);
    int val = suff[i];
    ;
    for (int j = 0; j < 201; j++) {
      val += min(r, oc[i - c - 1][j]) * j;
      r -= min(r, oc[i - c - 1][j]);
    }
    ans = min(ans, val);
    ;
    c = 1;
  }
  int r = max(0, n - 2 * c + 1);
  ;
  int val = 0;
  for (int j = 0; j < 201; j++) {
    val += min(r, oc[n - c - 1][j]) * j;
    r -= min(r, oc[n - c - 1][j]);
  }
  ans = min(ans, val);
  cout << ans << endl;
}
