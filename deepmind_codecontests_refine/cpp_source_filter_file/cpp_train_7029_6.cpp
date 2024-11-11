#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& arr) {
  for (long long i = 0; i < arr.size(); ++i) cin >> arr[i];
}
inline void solve() {
  long long n;
  cin >> n;
  vector<string> v(n);
  read(v);
  int ans = 6;
  vector<set<string> > st(7);
  for (int i = 0; i < 64; ++i) {
    string m;
    int c = 0;
    for (int k = 0; k < 6; ++k) {
      if ((i & (1 << k)) != 0) {
        m += "#";
        ++c;
      } else {
        m += ".";
      }
    }
    int col = 0;
    bool f = true;
    for (int ii = 0; ii < n; ++ii) {
      string t = v[ii];
      for (int j = 0; j < 6; ++j) {
        if (m[j] == '#') t[j] = '#';
      }
      if (st[c].find(t) == st[c].end()) {
        st[c].insert(t);
      } else {
        f = false;
        break;
      }
    }
    if (!f) ans = min(ans, c);
  }
  cout << ans;
}
void go() {
  int n;
  cin >> n;
  vector<string> v(n);
  read(v);
  int ans = 2;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int t = 0;
      for (int k = 0; k < 6; ++k) t += (v[i][k] == v[j][k]);
      t = 6 - t;
      if (t <= 2) ans = min(ans, 0);
      if (t == 3 || t == 4) ans = min(ans, 1);
      if (t == 5 || t == 6) ans = min(ans, 2);
    }
  }
  cout << ans;
}
int main() { go(); }
