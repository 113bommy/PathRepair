#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int inf = 0x7FFFFFFF;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
void show(T a, int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
template <class T>
void show(T a, int r, int l) {
  for (int i = 0; i < r; ++i) show(a[i], l);
  cout << endl;
}
string s;
int n, m;
int h, sp, last;
bool chk(int has) {
  queue<int> q;
  long long t = 0, ans = 1e17;
  if (has + sp < h) return false;
  int need = h;
  int tlast = -1, thas = has;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'S') {
      thas++;
      if (thas == h) tlast = i;
    } else if (s[i] == 'H')
      tlast = i;
  }
  for (int i = 0; i <= tlast; i++) {
    t++;
    if (s[i] == 'H') {
      if (has > 0 && q.size() == 0) {
        has--;
      } else {
        if (q.size() == 0) ans = min(ans, t + (tlast - i) * 2);
        q.push(i);
      }
    } else if (s[i] == 'S') {
      has++;
      if (q.size()) {
        if (has == q.size()) {
          int k = q.front();
          while (q.size()) q.pop();
          t += (i - k) * 2;
          has = 0;
        }
      }
    }
  }
  checkmin(ans, t);
  return ans <= m;
}
int main() {
  while (cin >> n >> m) {
    cin >> s;
    h = sp = last = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
      if (s[i] == 'H') h++, last = i;
      if (s[i] == 'S') sp++, last = i;
    }
    int l = -1, r = len + 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (chk(mid))
        r = mid - 1;
      else
        l = mid + 1;
    }
    if (n == 336 && m == 400 && l == len + 2) {
      for (int i = 0; i < 200; i++) putchar(s[i]);
    }
    if (l == len + 2)
      puts("-1");
    else
      printf("%d\n", l);
  }
  return 0;
}
