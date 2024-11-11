#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 9;
int n, k;
vector<int> a;
int f(int st) {
  int r = 0;
  for (int i = 0; i < n; ++i)
    if (a[i] != st + i * k) ++r;
  return r;
}
int main() {
  cin >> n >> k;
  a.resize(n);
  int r = -1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (r < a[i]) r = a[i];
  }
  int res = n + 5, wh;
  for (int i = 1; i <= r; ++i) {
    int t = f(i);
    if (t < res) {
      res = t;
      wh = i;
    }
  }
  cout << res << endl;
  for (int i = 0; i < n; ++i)
    if (a[i] > wh + i * k)
      cout << "+ " << i + 1 << ' ' << a[i] - wh - i * k << endl;
    else if (a[i] < wh + i * k)
      cout << "- " << i + 1 << ' ' << -a[i] + wh + i * k << endl;
  cout << "";
  return 0;
}
