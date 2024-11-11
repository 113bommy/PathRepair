#include <bits/stdc++.h>
using namespace std;
inline string GetString() {
  string res;
  char st[1000005];
  scanf("%s", st);
  res = st;
  return res;
}
inline string GetSent() {
  string res;
  char st[1000005];
  gets(st);
  res = st;
  return res;
}
template <typename t>
t in() {
  t res = 0;
  char c;
  int sign = 1;
  while (1) {
    c = getchar_unlocked();
    if (c == ' ' || c == '\n')
      continue;
    else
      break;
  }
  if (c == '+') {
  } else if (c == '-')
    sign = -1;
  else
    res = c - '0';
  while (1) {
    c = getchar_unlocked();
    if (c >= '0' && c <= '9')
      res = res * 10 + c - '0';
    else
      break;
  }
  return res * sign;
}
int main() {
  pair<int, int> app[100005];
  int n = in<int>(), m = in<int>(), k = in<int>();
  int isi[100005];
  for (int i = 0; i < n; i++) {
    int x = in<int>();
    app[x].first = i % k;
    app[x].second = i / k;
    isi[i] = x;
  }
  long long ans = 0;
  while (m--) {
    int x = in<int>();
    ans += (app[x].second + 1);
    if (app[x].first == 0 && app[x].second != 0) {
      int a = k - 1;
      int b = app[x].second - 1;
      int tot = b * k + a;
      int lala = isi[tot];
      isi[tot] = x;
      isi[tot + 1] = lala;
      swap(app[lala], app[x]);
    } else if (app[x].first > 0) {
      int a = app[x].first - 1;
      int b = app[x].second;
      int tot = b * k + a;
      int lala = isi[tot];
      isi[tot] = x;
      isi[tot + 1] = lala;
      swap(app[lala], app[x]);
    }
  }
  cout << ans << endl;
  return 0;
}
