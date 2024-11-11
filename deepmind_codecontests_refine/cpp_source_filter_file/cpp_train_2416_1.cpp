#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string x[n];
    set<string> S;
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
      S.insert(x[i]);
    }
    set<string> s;
    vector<string> v(n);
    int c = 0;
    for (int i = 0; i < n; ++i) {
      if (s.find(x[i]) == s.end()) {
        v[i] = x[i];
        s.insert(x[i]);
      } else {
        c++;
        int y = 1;
        while (1) {
          x[i][0] = char(int(x[i][0]) + 1);
          if (x[i][0] > '9') x[i][0] = 0;
          if (S.find(x[i]) == S.end()) {
            v[i] = x[i];
            S.insert(x[i]);
            s.insert(x[i]);
            break;
          }
        }
      }
    }
    cout << c << endl;
    for (auto i : v) cout << i << endl;
  }
}
