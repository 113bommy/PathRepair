#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
queue<int> q[maxn];
int n, m;
int main(void) {
  cin >> n;
  m = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x;
    if (q[x].empty()) {
      ++m;
      y = m;
      q[x].push(y);
    } else {
      y = q[x].front();
    }
    q[x].pop();
    q[i].push(y);
  }
  cout << m << endl;
  return 0;
}
