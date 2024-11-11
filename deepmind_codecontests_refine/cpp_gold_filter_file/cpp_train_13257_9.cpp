#include <bits/stdc++.h>
using namespace std;
inline const int read() {
  int r = 0, k = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') k = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) r = r * 10 + c - '0';
  return k * r;
};
int x[5005];
int y[5005];
int m[5005];
int k[5005];
int nk[5005];
pair<int, int> ans[200005];
int anst = 0;
set<pair<int, int> > s;
int temp, tpp;
int main() {
  ios::sync_with_stdio(false);
  int n;
  n = read();
  s.clear();
  int cnt = 0;
  int cnnt = 0;
  for (int i = 1; i <= n; i++) {
    k[i] = read();
    temp = read();
    x[i] = read();
    y[i] = read();
    m[i] = read();
    nk[i] = 0;
    s.insert(pair<int, int>(temp, i));
    cnnt = 0;
    for (int j = 1; j < k[i]; j++) {
      tpp = ((long long)x[i] * (long long)temp + (long long)y[i]) %
            ((long long)m[i]);
      if (tpp < temp) cnnt++;
      temp = tpp;
    };
    cnt = max(cnt, cnnt);
  };
  int nw = -1;
  pair<int, int> tp;
  set<pair<int, int> >::iterator it;
  while (!s.empty()) {
    it = s.upper_bound(pair<int, int>(nw, 0));
    if (it == s.end()) {
      nw = -1;
      it = s.upper_bound(pair<int, int>(nw, 0));
    };
    tp = *it;
    nw = tp.first;
    temp = tp.second;
    s.erase(it);
    if (anst < 200001)
      ans[anst++] = pair<int, int>(nw, temp);
    else
      break;
    nk[temp]++;
    if (nk[temp] < k[temp]) {
      s.insert(pair<int, int>(
          ((long long)x[temp] * (long long)nw + (long long)y[temp]) %
              ((long long)m[temp]),
          temp));
    };
  };
  printf("%d\n", cnt);
  if (anst < 200001)
    for (int i = 0; i < anst; i++)
      printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
};
