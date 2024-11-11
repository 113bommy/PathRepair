#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a;
  int cnt = 0;
  int sum = 0;
  for (int i = 0; i < 2 * n - 1; ++i) {
    int x;
    cin >> x;
    a.push_back(abs(x));
    if (x < 0) cnt++;
    sum += abs(x);
  }
  cnt %= n;
  queue<int> q;
  vector<bool> used(n + 1, false);
  used[cnt] = 1;
  q.push(cnt);
  int c = cnt;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (!used[n - u]) {
      used[n - u] = 1;
      q.push(n - u);
      c = min(c, n - u);
    }
    for (int i = 1; i <= u; ++i) {
      int to = u - i + n - i;
      to %= n;
      if (to >= 0 && !used[to]) {
        used[to] = 1;
        q.push(to);
        c = min(c, to);
      }
    }
  }
  sort(a.begin(), a.end());
  if (c == 0) {
    cout << sum;
  } else {
    for (int i = 0; i < c; ++i) {
      sum -= a[i];
    }
    cout << sum;
  }
  return 0;
}
