#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, t;
  cin >> n >> m;
  queue<int> a, b;
  for (int i = 1; i <= m; i++) cin >> t, a.push(t);
  cin >> t;
  for (int i = 1; i <= n - m; i++) cin >> t, b.push(t);
  int c = 0;
  while (c < 10 and !a.empty() and !b.empty()) {
    if (a.front() < b.front()) {
      int x = b.front();
      b.pop();
      b.push(a.front());
      a.pop();
      b.push(x);
    } else {
      int x = a.front();
      a.pop();
      a.push(b.front());
      b.pop();
      a.push(x);
    }
    c++;
  }
  if (!a.empty() and !b.empty())
    cout << -1;
  else {
    if (a.empty())
      cout << c << " " << 2;
    else if (b.empty())
      cout << c << " " << 1;
  }
  return 0;
}
