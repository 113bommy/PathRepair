#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000;
const int MAXLEN = 200000;
const int INF = 0x3f3f3f3f;
template <class T>
void Read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = 0;
  while (c < '0' || '9' < c) {
    if (c == '-') flag = 1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (flag) x = -x;
}
int len[MAXN + 10], fir[MAXN + 10], a[MAXN + 10], b[MAXN + 10], c[MAXN + 10];
int pos[MAXN + 10];
int n;
multiset<pair<int, int> > st;
pair<int, int> output[MAXLEN + 10];
int main() {
  int x, sum = 0;
  Read(n);
  for (int i = 1; i <= n; ++i) {
    Read(len[i]), Read(fir[i]);
    sum += len[i];
    Read(a[i]), Read(b[i]), Read(c[i]);
  }
  if (sum <= MAXN) {
    for (int i = 1; i <= n; ++i) st.insert(make_pair(fir[i], i));
    int ans = 0, tot = 0;
    int last = 0;
    while (st.size()) {
      set<pair<int, int> >::iterator it = st.lower_bound(make_pair(last, 0));
      if (it == st.end())
        ++ans, last = 0;
      else {
        last = (*it).first;
        output[++tot] = *it;
        if (--len[(*it).second])
          st.insert(make_pair(
              (1ll * (*it).first * a[(*it).second] + b[(*it).second]) %
                  c[(*it).second],
              (*it).second));
        st.erase(st.find(*it));
      }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= tot; ++i)
      printf("%d %d\n", output[i].first, output[i].second);
  } else {
    int ans = 0, t, x;
    for (int i = 1; i <= n; ++i) {
      t = 0;
      for (int j = 2; j <= len[i]; ++j) {
        x = (1ll * fir[i] * a[i] + b[i]) % c[i];
        t += (fir[i] > x);
        fir[i] = x;
      }
      ans = max(ans, t);
    }
    printf("%d\n", ans);
  }
}
