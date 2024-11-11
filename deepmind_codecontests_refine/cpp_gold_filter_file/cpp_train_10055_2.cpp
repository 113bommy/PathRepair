#include <bits/stdc++.h>
const int BSZ = 512, BNUM = 200010 / BSZ + 10;
int n, m;
long long ans;
int L[BNUM], R[BNUM], bel[200010], s[200010];
std::vector<int> V[BNUM];
int query(int l, int r, int x) {
  if (l > r) return 0;
  const int lb = bel[l], rb = bel[r];
  int res = 0;
  if (lb == rb)
    for (int i = l; i <= r; ++i) res += s[i] < x;
  else {
    for (int i = l; i <= R[lb]; ++i) res += s[i] < x;
    for (int i = lb + 1; i < rb; ++i)
      res += std::upper_bound(V[i].begin(), V[i].end(), x) - V[i].begin();
    for (int i = L[rb]; i <= r; ++i) res += s[i] < x;
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) V[bel[i] = (i >> 9) + 1].push_back(s[i] = i);
  const int B = bel[n];
  for (int i = 1; i <= B; ++i) {
    L[i] = i - 1 << 9;
    R[i] = L[i] + BSZ - 1;
  }
  L[1] = 1, R[B] = n;
  while (m-- > 0) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l == r) {
      printf("%lld\n", ans);
      continue;
    }
    if (l > r) std::swap(l, r);
    const int lb = bel[l], rb = bel[r];
    ans += (query(l + 1, r - 1, s[r]) - query(l + 1, r - 1, s[l])) * 2;
    ans += (s[l] < s[r]) ? 1 : -1;
    printf("%lld\n", ans);
    if (lb != rb) {
      V[lb].erase(std::lower_bound(V[lb].begin(), V[lb].end(), s[l]));
      V[lb].insert(std::upper_bound(V[lb].begin(), V[lb].end(), s[r]), s[r]);
      V[rb].erase(std::lower_bound(V[rb].begin(), V[rb].end(), s[r]));
      V[rb].insert(std::upper_bound(V[rb].begin(), V[rb].end(), s[l]), s[l]);
    }
    std::swap(s[l], s[r]);
  }
  return 0;
}
