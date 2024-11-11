#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, i, a, c;
  vector<int> v;
  vector<double> v1;
  double b;
  cin >> n;
  c = 0;
  for (i = 0; i < n; i++) {
    cin >> b;
    v1.push_back(b);
    a = (int)b;
    v.push_back(a);
    c = c + a;
  }
  if (c == 0) {
    for (i = 0; i < n; i++) {
      cout << v[i] << endl;
    }
  } else {
    if (c < 0) {
      c = abs(c);
      for (i = 0; i < n; i++) {
        if (v1[i] != v[i] && v[i] >= 0 && c > 0) {
          v[i]++;
          c--;
        }
      }
    } else {
      for (i = 0; i < n; i++) {
        if (v1[i] != v[i] && v[i] < 0 && c > 0) {
          v[i]--;
          c--;
        }
      }
    }
    for (i = 0; i < n; i++) {
      cout << v[i] << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
