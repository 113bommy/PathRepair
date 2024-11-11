#include <bits/stdc++.h>
using namespace std;
const int MAXN = 501;
int x[MAXN];
int y[MAXN];
int num[MAXN];
int ans[MAXN];
queue<int> q[200001];
int S(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }
int Calc(int a, int b, int c) { return S(a, b) + S(b, c); }
int Solve(int n, int m) {
  multiset<int> s;
  for (int i = 0; i < n; i++)
    if (!(i & 1)) s.insert(Calc((i - 2 + n) % n, (i - 1 + n) % n, i));
  for (int i = 0; i < m; i++) {
    multiset<int>::iterator it = s.find(num[i]);
    if (it != s.end()) s.erase(it);
  }
  return s.size() == 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 0; i < m; i++) {
    cin >> num[i];
    q[num[i]].push(i + 1);
  }
  int f = Solve(n, m);
  int cont = 0;
  if (!f) {
    int x_ = x[0], y_ = y[0];
    for (int i = 0; i < n - 1; i++) {
      x[i] = x[i + 1];
      y[i] = y[i + 1];
    }
    x[n - 1] = x_;
    y[n - 1] = y_;
    f = Solve(n, m);
    cont++;
  }
  if (!f)
    cout << "NO" << '\n';
  else {
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      int h = (i - 1 + n) % n;
      if (cont) h = (h + 1 + n) % n;
      if (!(i & 1)) {
        ans[h] = q[Calc((i - 2 + n) % n, (i - 1 + n) % n, i)].front();
        q[Calc((i - 2 + n) % n, (i - 1 + n) % n, i)].pop();
      } else
        ans[h] = -1;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << '\n';
  }
  return 0;
}
