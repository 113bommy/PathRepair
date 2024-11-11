#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, i, c = 0, a, b;
  set<int> s;
  set<int>::iterator it;
  cin >> n >> m;
  while (m--) {
    cin >> a >> b;
    s.insert(a);
    s.insert(b);
  }
  if (n == 1) {
    cout << "0" << endl;
    return;
  }
  for (i = 1; i <= n; i++) {
    c = 0;
    for (it = s.begin(); it != s.end(); it++) {
      if (i == *it) {
        c = 1;
        break;
      }
    }
    if (c == 0) {
      c = i;
      break;
    }
  }
  cout << n - 1 << endl;
  for (i = 1; i <= n; i++) {
    if (i != c) {
      cout << i << " " << c << endl;
    }
  }
  return;
}
int main() { solve(); }
