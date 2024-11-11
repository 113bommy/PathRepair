#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long calc_cap(int k) {
  long long ans = n;
  int Last = 1, rem = n - 1;
  for (int l = 1; l <= n && rem > 0; ++l) {
    long long now = 1LL * Last * k;
    if (now > rem) {
      now = rem;
      rem = 0;
    } else
      rem -= now;
    ans = ans + 1LL * now * l;
    Last = now;
  }
  return ans;
}
int find_cap(int n, long long s) {
  int st = 1, dr = n - 1;
  while (st <= dr) {
    int mij = (st + dr) / 2;
    if (calc_cap(mij) <= s)
      dr = mij - 1;
    else
      st = mij + 1;
  }
  return st;
}
vector<int> solve(int n, long long s) {
  int cap = find_cap(n, s);
  vector<deque<int>> dq(n + 1);
  vector<int> par(n + 1), cnt(n + 1), H(n + 1);
  long long sum = 1LL * n * (n + 1) / 2;
  for (int i = 0; i < n; ++i) {
    dq[i].push_back(i + 1);
    par[i + 1] = i;
    H[i + 1] = i;
    ++cnt[i];
  }
  int lev = 0;
  long long dif = sum - s;
  for (int nod = n; nod >= 1 && dif > 0; --nod) {
    while (dq[lev].size() == 0) ++lev;
    int h = (nod - 1) - lev - 1;
    if (h <= dif)
      dif -= h;
    else {
      lev = (nod - 1) - dif - 1;
      dif = 0;
    }
    --cnt[par[nod]];
    par[nod] = dq[lev].front();
    ++cnt[par[nod]];
    if (cnt[par[nod]] == cap) dq[lev].pop_front();
    dq[nod - 1].pop_front();
    dq[lev + 1].push_back(nod);
    H[nod] = lev + 1;
  }
  return par;
}
int main() {
  scanf("%d%lld", &n, &m);
  if (!(n + n - 1 <= m && m <= 1LL * n * (n + 1) / 2)) {
    printf("NO");
    return 0;
  }
  auto sol = solve(n, m);
  printf("YES\n");
  for (auto it : sol)
    if (it != 0) printf("%d ", it);
  return 0;
}
