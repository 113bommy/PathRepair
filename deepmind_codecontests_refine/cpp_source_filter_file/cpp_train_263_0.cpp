#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> from, to;
  for (int i = 0; i < n; ++i) {
    int s, d;
    cin >> s >> d;
    bool puc = true;
    for (int j = 0; j < i; ++j) {
      if (from[j] < s + d and s < to[j]) puc = false;
    }
    if (puc) {
      cout << s << ' ' << s + d - 1 << '\n';
      from.push_back(s);
      to.push_back(s + d);
    } else {
      int pos = 2e9;
      for (int j = 0; j < i; ++j) {
        int ss = to[j];
        puc = true;
        for (int k = 0; k < i; ++k)
          if (k != j) {
            if (from[j] < ss + d and ss < to[j]) puc = false;
          }
        if (puc) pos = min(pos, ss);
      }
      int ss = 1;
      puc = true;
      for (int k = 0; k < i; ++k) {
        if (from[k] < ss + d and ss < to[k]) puc = false;
      }
      if (puc) pos = min(pos, ss);
      cout << pos << ' ' << pos + d - 1 << '\n';
      from.push_back(pos);
      to.push_back(pos + d);
    }
  }
}
