#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    long a;
    stack<long> f;
    queue<long> g;
    int d = 0;
    cin >> a;
    f.push(a);
    for (int i = 2; i <= m; i++) {
      cin >> a;
      if (a > f.top()) {
        while (a > f.top()) {
          d++;
          g.push(f.top());
          f.pop();
          if (f.empty() == true) break;
        }
        f.push(a);
        while (g.empty() == false) {
          f.push(g.front());
          g.pop();
        }
      } else
        f.push(a);
    }
    cout << d << endl;
  }
  return 0;
}
