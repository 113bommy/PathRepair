#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
vector<int> pr;
int l[N + 1];
void init() {
  for (int i = 2; i <= N; ++i) {
    if (!l[i]) {
      pr.push_back(i);
      l[i] = i;
    }
    for (int j = 0; j < pr.size() && pr[j] <= l[i] && pr[j] * i <= N; ++j)
      l[pr[j] * i] = pr[j];
  }
}
int x, p, k;
vector<int> pd;
int tox;
void getp() {
  int p_ = p;
  pd.clear();
  while (p_ != 1) {
    int t = l[p_];
    pd.push_back(t);
    do {
      p_ /= t;
    } while (l[p_] == t);
  }
}
int amt(int to) {
  int amt = 1;
  int m = 1 << pd.size();
  for (int bit = 1; bit < m; ++bit) {
    int k = 1;
    for (int j = 0; j < pd.size(); ++j)
      if ((bit >> j) & 1) k *= pd[j];
    amt += ((__builtin_popcount(bit) & 1) * 2 - 1) * (to / k);
  }
  return to - amt;
}
bool test(int a) { return amt(a) - tox >= k; }
int main() {
  init();
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &x, &p, &k);
    getp();
    int ans;
    int l = x + 1;
    int r = N * 10;
    tox = amt(x);
    while (l <= r) {
      int m = (l + r) / 2;
      if (test(m)) {
        ans = m;
        r = m - 1;
      } else
        l = m + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
