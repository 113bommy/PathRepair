#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
const int B = 100;
inline int read() {
  int x = 0;
  bool f = true;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = false;
    c = getchar();
  }
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return f ? x : -x;
}
int tot, p[N];
bool isnp[N];
inline void filt(int w) {
  for (register int i = 2; i <= w; ++i) {
    if (!isnp[i]) p[++tot] = i;
    for (int j = 1; j <= tot && i * p[j] <= w; ++j) {
      isnp[i * p[j]] = true;
      if (!(i % p[j])) break;
    }
  }
}
int n, Ans, cur;
bool tag[N], flag;
vector<int> fac;
inline int askA(int x) {
  cout << "A " << x << endl;
  fflush(stdout);
  int res;
  cin >> res;
  return res;
}
inline int askB(int x) {
  cout << "B " << x << endl;
  fflush(stdout);
  int res;
  cin >> res;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  filt(n);
  cur = n;
  for (register int i = 1; i <= tot; ++i) {
    int ans = askB(p[i]), res = 0;
    for (int j = p[i]; j <= n; j += p[i]) res += !tag[j], tag[j] = true;
    if (res != ans) fac.push_back(p[i]);
    cur -= res;
    if (flag || (i < tot && i % B)) continue;
    ans = askA(1);
    if (ans != cur) {
      flag = true;
      int l = (i - 1) / B * B;
      for (register int j = l + 1; j <= i; ++j) {
        if (askA(p[j])) {
          fac.push_back(p[j]);
          break;
        }
      }
    }
  }
  Ans = 1;
  for (int i : fac) {
    for (int x = i; x <= n && askA(x); x *= i) Ans *= i;
  }
  cout << "C " << Ans << endl;
  return 0;
}
