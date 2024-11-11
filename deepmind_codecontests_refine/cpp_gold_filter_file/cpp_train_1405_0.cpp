#include <bits/stdc++.h>
using namespace std;
int n, m, k, l, r, ans, mx, a[5122];
string s;
bool f;
vector<pair<int, int> > v;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int j = 1; j <= n + 1; ++j) {
    f = true;
    for (int i = 1; i <= n; ++i) {
      if (f) {
        a[i] = (a[i] + 1) % n;
        f = false;
      } else {
        a[i]--;
        if (a[i] == -1) a[i] = n - 1;
        f = true;
      }
    }
    bool w = true;
    for (int i = 2; i <= n; ++i) {
      if (a[i] - a[i - 1] == 1)
        s = "1";
      else
        w = false;
    }
    if (w) return cout << "Yes", 0;
  }
  cout << "No";
}
