#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline void read(_T &_x) {
  int _t;
  bool _flag = false;
  while ((_t = getchar()) != '-' && (_t < '0' || _t > '9'))
    ;
  if (_t == '-') _flag = true, _t = getchar();
  _x = _t - '0';
  while ((_t = getchar()) >= '0' && _t <= '9') _x = _x * 10 + _t - '0';
  if (_flag) _x = -_x;
}
const int maxn = 100010;
int n, m;
int c[maxn], w[maxn];
bool change[maxn];
priority_queue<pair<int, int> > h;
int main() {
  read(n), read(m);
  for (int i = 1; i <= n; ++i) read(c[i]);
  for (int i = 1; i <= n; ++i) read(w[i]);
  long long anger = 0;
  for (int i = 1; i <= n; ++i) {
    int ret = c[i] % 100;
    m -= ret;
    if (ret) h.push(make_pair(-(100 - ret) * w[i], i));
    if (m < 0) {
      m += 100;
      pair<int, int> tmp = h.top();
      change[tmp.second] = true;
      anger -= tmp.first;
      h.pop();
    }
  }
  cout << anger << endl;
  for (int i = 1; i <= n; ++i) {
    if (change[i]) {
      cout << c[i] / 100 + 1 << ' ' << 0 << '\n';
    } else {
      cout << c[i] / 100 << ' ' << c[i] % 100 << '\n';
    }
  }
  return 0;
}
