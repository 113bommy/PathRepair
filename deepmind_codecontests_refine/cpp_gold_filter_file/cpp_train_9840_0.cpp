#include <bits/stdc++.h>
using namespace std;
class solve {
 private:
  int n, lar, les;
  vector<int> val[2];
  vector<int> res[2];
  vector<long long> sum[2];

 private:
  int find_first_less(int i);

 public:
  void func();
};
void solve::func() {
  cin >> n;
  val[0].resize(n + 1, 0);
  val[1].resize(n + 1, 0);
  sum[0].resize(n + 1, 0);
  sum[1].resize(n + 1, 0);
  for (int k = 0; k < 2; k++)
    for (int i = 1; i <= n; i++) {
      scanf("%d", &val[k][i]);
      sum[k][i] = sum[k][i - 1] + val[k][i];
    }
  if (sum[0][n] >= sum[1][n])
    lar = 0;
  else
    lar = 1;
  les = 1 - lar;
  map<long long, pair<int, int> > diff_pair;
  diff_pair[0] = make_pair(0, 0);
  for (int i = 1; i <= n; i++) {
    int l = 0, r = n, m;
    while (l < r) {
      m = (l + r + 1) / 2;
      if (sum[les][i] >= sum[lar][m])
        l = m;
      else
        r = m - 1;
    }
    long long diff = sum[les][i] - sum[lar][l];
    if (diff_pair.count(diff) != 0) {
      for (int j = diff_pair[diff].first + 1; j <= i; j++)
        res[les].push_back(j);
      for (int j = diff_pair[diff].second + 1; j <= l; j++)
        res[lar].push_back(j);
      break;
    } else
      diff_pair[diff] = make_pair(i, l);
  }
  printf("%d\n", (int)res[0].size());
  for (int i = 0; i < res[0].size(); i++) printf("%d ", res[0][i]);
  printf("\n");
  printf("%d\n", (int)res[1].size());
  for (int i = 0; i < res[1].size(); i++) printf("%d ", res[1][i]);
  printf("\n");
}
int main() {
  solve s;
  s.func();
  return 0;
}
