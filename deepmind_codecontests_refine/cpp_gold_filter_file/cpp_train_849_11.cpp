#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 9;
int n;
int fs[maxn];
int pj[maxn];
long long ansji, ansou;
void solve() {
  int i;
  for (i = 1; i <= n; ++i) fs[i] += fs[i - 1];
  for (i = 1; i <= n; ++i) {
    pj[i] = pj[i - 1] + (fs[i] & 1);
  }
  for (i = 1; i <= n; ++i) {
    if (fs[i] & 1) {
      ansji += i - pj[i - 1];
      ansou += pj[i - 1];
    } else {
      ansji += pj[i - 1];
      ansou += i - pj[i - 1];
    }
  }
}
void _solve() {
  solve();
  cout << ansji << " " << ansou << endl;
}
void _prepare() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    fs[i] = x < 0;
  }
}
int _main_prog() {
  _prepare();
  _solve();
  return 0;
}
int main() { return _main_prog(); }
