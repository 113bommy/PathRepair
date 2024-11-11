#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v[1000001];
bool death[1000001];
int n, k, s[5005], par[5005];
int f(int x) { return par[x] == x ? x : par[x] = f(par[x]); }
int involve[5005], p, lis[5005];
bool gen[1000001];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = (1); i <= (n); i++) scanf("%d", &s[i]);
  sort(s + 1, s + n + 1);
  for (int i = (1); i <= (n); i++)
    for (int j = (i + 1); j <= (n); j++) {
      int diff = s[j] - s[i];
      int sz = v[diff].size();
      if (!death[diff]) {
        v[diff].push_back(make_pair(i, j));
        if (sz == k) death[diff] = 1;
      die:;
      }
    }
  for (int i = (1); i <= (n); i++) par[i] = i;
  for (int i = (1); i <= (1000001); i++) {
    int cnt = 0, cc = 0;
    p = 0;
    for (int j = i; j <= 1000000; j += i) {
      cc += v[j].size();
      if (cc > k * (k + 1) / 2) goto gg;
      if (death[j]) goto gg;
    }
    for (int j = (1); j <= (n); j++) {
      if (gen[s[j] % i] == 0)
        gen[s[j] % i] = 1;
      else {
        cnt++;
        if (cnt > k) goto gg;
      }
    }
    printf("%d\n", i);
    return 0;
  gg:;
  }
}
