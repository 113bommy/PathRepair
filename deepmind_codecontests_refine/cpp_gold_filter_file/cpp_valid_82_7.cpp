#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 1e6;
const long long MOD = 1e9 + 7;
using namespace std;
long long q, x, y, z, n, m, a[KL], mn = 1e9, mx = -1e9, ans;
string t;
long long fr[2][KL], pr[KL];
set<int> vv[KL], uu[KL];
int main() {
  long long T;
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld", &n);
    scanf("%lld", &q);
    cin >> t;
    for (int i = 0; i <= n; i++) vv[i].clear(), uu[i].clear();
    for (int i = 0; i < n; i++) {
      if ((i + 1) % 2 == 1) {
        if (t[i] == '+')
          t[i] = '-';
        else
          t[i] = '+';
      }
    }
    for (int i = 1; i <= n; i++) {
      if (t[i - 1] == '-') {
        pr[i] = -1 + pr[i - 1];
      } else {
        pr[i] = 1 + pr[i - 1];
      }
      if (pr[i] >= 0) {
        vv[pr[i]].insert(i);
      } else {
        uu[abs(pr[i])].insert(i);
      }
    }
    while (q--) {
      scanf("%lld", &x);
      scanf("%lld", &y);
      long long ret = pr[y] - pr[x - 1];
      if (ret == 0) {
        printf("0\n");
        continue;
      }
      vector<long long> vec;
      if (ret % 2 == 0) {
        vec.push_back(x);
        x++;
      }
      ret = pr[y] - pr[x - 1];
      if (ret < 0)
        ret--;
      else
        ret++;
      long long v = ret / 2;
      auto it = vv[0].begin();
      if (v + pr[x - 1] >= 0) {
        it = vv[v + pr[x - 1]].lower_bound(x);
      } else {
        it = uu[abs(v + pr[x - 1])].lower_bound(x);
      }
      vec.push_back(*it);
      printf("%d\n", (int)vec.size());
      sort(vec.begin(), vec.end());
      for (int i = 0; i < vec.size(); i++) {
        printf("%lld ", vec[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
