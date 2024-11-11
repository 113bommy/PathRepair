#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> fun(long long x, long long n) {
  long long i = 0, j = 0, k = 0, tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp = 0,
            tmp4 = 0, tmp5 = 0, flag = 0, T = 0, N = 0, Q = 0;
  tmp = 6 * x - n + n * n * n;
  if (tmp == 0) return make_pair(-1, -1);
  if (tmp % 3) return make_pair(-1, -1);
  tmp /= 3;
  if (tmp % n) return make_pair(-1, -1);
  tmp /= n;
  if (tmp % (n + 1)) return make_pair(-1, -1);
  tmp /= (n + 1);
  if (n > tmp) return make_pair(-1, -1);
  return make_pair(n, tmp);
}
int main() {
  long long i = 0, j = 0, k = 0, tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp = 0,
            tmp4 = 0, tmp5 = 0, flag = 0, T = 0, N = 0, Q = 0;
  long long x;
  pair<long long, long long> pr;
  cin >> x;
  vector<pair<long long, long long> > ans;
  tmp = 1000001;
  for (i = 1; i < min(x + 1, tmp); i++) {
    pr = fun(x, i);
    if (pr.first != -1) ans.push_back(pr);
  }
  if (ans.size() == 0) {
    printf("Empty");
    return 0;
  }
  if (ans.back().first == ans.back().second) {
    printf("%d\n", 2 * ans.size() - 1);
    for (i = 0; i < ans.size(); i++) {
      cout << ans[i].first << " " << ans[i].second << endl;
    }
    if (ans.size() > 1)
      for (i = ans.size() - 2; i > -1; i--) {
        cout << ans[i].second << " " << ans[i].first << endl;
      }
  } else {
    printf("%d\n", 2 * ans.size());
    for (i = 0; i < ans.size(); i++) {
      cout << ans[i].first << " " << ans[i].second << endl;
    }
    for (i = ans.size() - 1; i > -1; i--) {
      cout << ans[i].second << " " << ans[i].first << endl;
    }
  }
  return 0;
}
