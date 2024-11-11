#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  char c;
  cin >> n >> c;
  string s;
  cin >> s;
  long long int o = 0, e = 0;
  long long int vo, ve;
  for (long long int i = 1; i <= n; i++) {
    if (s[i - 1] != c) {
      if (i % 2) {
        o++;
        vo = i;
      } else {
        e++;
        ve = i;
      }
    }
  }
  if (o == 0 and e == 0) {
    cout << 0 << endl;
  } else if (o == 0) {
    cout << 1 << endl;
    if (ve - 1 != 1)
      cout << ve - 1 << endl;
    else {
      cout << ve + 1 << endl;
    }
  } else if (e == 0) {
    cout << 1 << endl << 2 << endl;
  } else {
    vector<long long int> idx, b;
    for (long long int i = 1; i <= n; i++) {
      if (s[i - 1] == c) {
        idx.push_back(i);
      } else {
        b.push_back(i);
      }
    }
    for (auto i : idx) {
      long long int j = i;
      long long int cnt = 1;
      long long int flag = 1;
      while (j * cnt < n) {
        if (binary_search(b.begin(), b.end(), j * cnt)) {
          flag = 0;
          break;
        }
        cnt++;
      }
      if (flag) {
        cout << 1 << endl << i << endl;
        return;
      }
    }
    cout << 2 << endl;
    if (ve - 1 != 1)
      cout << "2 " << ve - 1 << endl;
    else {
      cout << "2 " << ve + 1 << endl;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
