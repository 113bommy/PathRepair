#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n, m, ans;
int num[maxn];
set<int> st[2];
set<int>::iterator it, itt;
void get_st(int begin, int end, set<int> &st) {
  st.clear();
  st.insert(0);
  for (int i = 0; i < (1 << (end - begin)); ++i) {
    int tmp = 0;
    for (int j = 0; j < end - begin; ++j) {
      if (((i >> j) & 1) == 1) {
        tmp = (tmp + num[j]) % m;
      }
    }
    st.insert(tmp);
  }
}
int main() {
  ios::sync_with_stdio(false);
  while (scanf("%d%d", &n, &m) != EOF) {
    ans = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &num[i]);
    }
    get_st(0, (n + 1) / 2, st[0]);
    get_st((n + 1) / 2, n, st[1]);
    for (it = st[0].begin(); it != st[0].end(); ++it) {
      for (int i = 1; i <= 2; ++i) {
        itt = st[1].lower_bound(m * i - *it);
        if (itt != st[1].begin()) {
          --itt;
          ans = max(ans, (*it + *itt) % m);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
