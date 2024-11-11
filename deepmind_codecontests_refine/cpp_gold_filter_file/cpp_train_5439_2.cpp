#include <bits/stdc++.h>
using namespace std;
int t;
string q;
stack<pair<int, int> > s;
int main() {
  cin >> t;
  int i, j;
  while (t > 0) {
    cin >> q;
    int tmp = 0;
    int n = q.length();
    for (i = 0; i < n; ++i) {
      if (q[i] == '0') continue;
      s.push(make_pair((int)q[i] - 48, n - 1 - i));
    }
    cout << s.size() << '\n';
    while (!s.empty()) {
      cout << s.top().first * pow(10, s.top().second) << ' ';
      s.pop();
    }
    cout << '\n';
    --t;
  }
  return 0;
}
