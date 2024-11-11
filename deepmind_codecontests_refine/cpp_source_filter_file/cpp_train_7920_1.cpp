#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
int cf[200000];
int n, m;
int ask(int x) {
  int res;
  cout << x << endl;
  cin >> res;
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    int res = ask(m);
    if (res == 0) return 0;
    if (res == 1)
      cf[i] = 1;
    else
      cf[i] = -1;
  }
  int it = 1;
  int l = 1;
  int r = m;
  while (r - l > 0) {
    int mid = (r + l) / 2;
    int res = ask(mid);
    if (res == 0) return 0;
    res *= cf[it];
    if (res == -1)
      r = mid - 1;
    else
      l = mid + 1;
    it++;
    if (it > n) it = 1;
  }
  cout << l << "\n";
  return 0;
}
