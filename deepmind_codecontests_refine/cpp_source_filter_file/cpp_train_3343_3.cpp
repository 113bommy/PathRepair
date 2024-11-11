#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
char s[1000009], t[1000009];
int cnt[2];
int pw[1000009], par[1000009];
int wp[1000009], rap[1000009];
int mod(long long x) {
  x %= 1000000007;
  if (x < 0) x += 1000000007;
  return x;
}
pair<int, int> get(int l, int r) {
  return make_pair(mod(par[r] - (par[l - 1] * 1LL * pw[r - l + 1])),
                   mod(rap[r] - (rap[l - 1] * 1LL * wp[r - l + 1])));
}
int main() {
  scanf("%s", s);
  int n = strlen(s);
  scanf("%s", t + 1);
  int m = strlen(t + 1);
  pw[0] = wp[0] = 1;
  for (int i = 1; i < 1000009; i++) {
    pw[i] = mod(pw[i - 1] * 27LL);
    wp[i] = mod(wp[i - 1] * 31LL);
  }
  for (int i = 1; i <= m; i++) {
    par[i] = mod(par[i - 1] * 27LL + (t[i] - 'a' + 1));
    rap[i] = mod(rap[i - 1] * 31LL + (t[i] - 'a' + 1));
  }
  for (int i = 0; i < n; i++) cnt[s[i] - '0']++;
  int ans = 0;
  for (int i = 1; i * cnt[0] <= m and i < m; i++)
    if ((m - i * cnt[0]) % cnt[1] == 0) {
      int d = (m - i * cnt[0]) / cnt[1];
      pair<int, int> a, b;
      a.first = b.first = -1;
      int cur = 1, f = 1;
      for (int j = 0; j < n; j++) {
        if (s[j] == '0') {
          if (a.first == -1)
            a = get(cur, cur + i - 1);
          else
            f &= (a == get(cur, cur + i - 1));
          cur += i;
        } else {
          if (b.first == -1)
            b = get(cur, cur + d - 1);
          else
            f &= (b == get(cur, cur + d - 1));
          cur += d;
        }
      }
      if (f and d == i and a == b) f = 0;
      ans += f;
    }
  printf("%d\n", ans);
  return 0;
}
