#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30);
int convert(string s) {
  stringstream ss(s);
  int x;
  ss >> x;
  return x;
}
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> s;
    if (s[0] == '?') {
      v[i] = INF;
    } else {
      v[i] = convert(s);
    }
  }
  for (int i = 0; i < k; ++i) {
    int start = i - k;
    int l = 0;
    int j;
    for (j = i; j < n; j += k) {
      if (v[j] != INF) {
        int mn = (start == i - k) ? -INF : v[start];
        int mx = v[j];
        if (l >= mx - mn) {
          cout << "Incorrect sequence" << endl;
          return 0;
        }
        int beg = -(l - 1) / 2;
        int end = beg + l - 1;
        if (beg <= mn) {
          beg = mn + 1;
          end = beg + l - 1;
        }
        if (end >= mx) {
          end = mx - 1;
          beg = end - l + 1;
        }
        for (int u = start + k; u < j; u += k) v[u] = beg + (u - start - k) / k;
        start = j;
        l = 0;
      } else
        ++l;
    }
    int mn = (start == i - k) ? -INF : v[start];
    int mx = INF;
    if (l >= mx - mn) {
      cout << "Incorrect sequence" << endl;
      return 0;
    }
    int beg = -(l - 1) / 2;
    int end = beg + l - 1;
    if (beg <= mn) {
      beg = mn + 1;
      end = beg + l - 1;
    }
    if (end >= mx) {
      end = mx - 1;
      beg = end - l + 1;
    }
    for (int u = start + k; u < j; u += k) v[u] = beg + (u - start - k) / k;
    start = j;
    l = 0;
  }
  for (int i = 0; i < n; ++i) cout << (i ? " " : "") << v[i];
  cout << endl;
}
