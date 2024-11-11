#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
long long t2[N], t3[N];
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  s += "#####";
  long long res = 0;
  set<string> suffs;
  t2[n - 2] = 1;
  t3[n - 3] = 1;
  for (int i = n - 1; i >= 5; --i) {
    if (i + 3 < n) {
      if (s.substr(i, 3) != s.substr(i + 3, 3)) {
        t3[i] += t3[i + 3];
      }
      if (t2[i + 3] > 0) {
        t3[i] += t2[i + 3];
      }
    }
    if (i + 2 < n) {
      if (s.substr(i, 2) != s.substr(i + 2, 2)) {
        t2[i] += t2[i + 2];
      }
      if (t3[i + 2] > 0) {
        t2[i] += t3[i + 2];
      }
    }
    if (t2[i] > 0) {
      suffs.insert(s.substr(i, 2));
    }
    if (t3[i] > 0) {
      suffs.insert(s.substr(i, 3));
    }
  }
  cout << suffs.size() << endl;
  for (string x : suffs) {
    cout << x << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(7) << std::fixed;
  solve();
  return 0;
}
