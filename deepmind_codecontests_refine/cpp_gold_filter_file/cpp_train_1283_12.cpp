#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int v[MAXN], v2[MAXN], ok[MAXN];
vector<int> t;
int k[MAXN];
int main() {
  int n, m, cnt = 0, ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    t.push_back(a);
    if (a < 0) {
      cnt++;
      v2[-a]++;
    } else {
      v[a]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (v[i] + cnt - v2[i] == m) {
      ok[i] = 1;
      ans++;
    }
  }
  for (int i = 0; i < n; i++) {
    bool f = 0, f2 = 0;
    if (t[i] > 0) {
      if (ok[t[i]]) {
        f = 1;
        if (ans > 1) f2 = 1;
      } else {
        f2 = 1;
      }
    } else {
      if (ok[-t[i]]) {
        f2 = 1;
        if (ans > 1) f = 1;
      } else {
        f = 1;
      }
    }
    if (f && f2) {
      cout << "Not defined" << endl;
    } else if (f) {
      cout << "Truth" << endl;
    } else {
      cout << "Lie" << endl;
    }
  }
  return 0;
}
