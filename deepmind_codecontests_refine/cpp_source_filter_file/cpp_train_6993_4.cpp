#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 3;
int t[MAXN];
int licz[MAXN];
vector<int> v[MAXN];
int main() {
  int n, z;
  scanf("%d %d", &n, &z);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    v[t[i]].push_back(i);
  }
  for (int i = 1; i < MAXN; i++) reverse(v[i].begin(), v[i].end());
  int nxt = 0, mx = 0;
  int akt, pop = 0;
  int wyn = 0;
  for (int i = 1; i <= n; i++) {
    akt = t[i];
    v[akt].pop_back();
    if (!v[akt].empty()) nxt = max(nxt, v[akt].back());
    licz[akt]++;
    if (licz[akt] > mx) mx = licz[akt];
    if (nxt == i) {
      wyn += i - pop - mx;
      pop = i;
      mx = 0;
      nxt = i + 1;
    }
  }
  printf("%d", wyn);
  return 0;
}
