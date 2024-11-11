#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0;
  int b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
const int _ = 200007, __ = 2000007, mo = 1000000007;
int isnp[__] = {0}, lasp[__] = {0};
void fuck(int n = __ - 1) {
  for (int i = 2; i <= n; i++) {
    if (isnp[i]) continue;
    lasp[i] = i;
    for (long long j = 1ll * i * i; j <= n; j += i) {
      isnp[j] = 1;
      if (!lasp[j]) lasp[j] = i;
    }
  }
}
map<int, pair<int, int>> mp;
void gmax(int who, int d) {
  if (!who) return;
  if (mp[who].first < d) mp[who].second = 0;
  if (mp[who].first <= d) mp[who].first = d, mp[who].second++;
}
void add(int x) {
  int las = 0, cnt = 0;
  while (x > 1) {
    int a = lasp[x];
    x /= a;
    if (las != a) gmax(las, cnt), cnt = 0;
    las = a, cnt++;
  }
  if (cnt) gmax(las, cnt);
}
int finder(int x) {
  int las = 0, cnt = 0;
  while (x > 1) {
    int a = lasp[x];
    x /= a;
    if (las != a) {
      if (las && mp[las].first == cnt && mp[las].second == 1) return 0;
      cnt = 0;
    }
    las = a, cnt++;
  }
  if (las && mp[las].first == cnt && mp[las].second == 1) return 0;
  return 1;
}
int n, val[_], fr[__] = {0};
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  fuck();
  n = ty();
  for (int i = 1; i <= n; i++) val[i] = ty();
  sort(val + 1, val + n + 1, greater<int>());
  for (int i = 1, j = 1; i <= n; i = j + 1) {
    j = i;
    while (j < n && val[i] == val[j + 1]) j++;
    add(val[i]);
  }
  for (int i = 1, j = 1; i <= n; i = j + 1) {
    j = i;
    while (j < n && val[i] == val[j + 1]) j++;
    int cnt = j - i + 1;
    if (cnt + finder(val[i]) >= 2) {
      if (cnt == 1) {
        fr[val[i]] = 1;
        if (mp[val[i]].first == 1) mp[val[i]].second--;
      }
      add(val[i] - 1);
    }
  }
  int temp = 0;
  for (int i = 1, j = 1; i <= n; i = j + 1) {
    j = i;
    while (j < n && val[i] == val[j + 1]) j++;
    int cnt = j - i + 1;
    if (cnt + (cnt == 1 ? fr[val[i]] : finder(val[i])) + finder(val[i] - 1) >=
        3)
      temp = 1;
  }
  long long ans = 1;
  for (auto i : mp)
    while (i.second.first--) ans = ans * i.first % mo;
  if (temp) ans = (ans + 1) % mo;
  cout << ans << lf;
  return 0;
}
