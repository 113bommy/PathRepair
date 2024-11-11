#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
struct cycle {
  vector<int> cur;
  cycle(int n = 0) {
    cur.resize(n, 0);
    for (int k = 0; k < (cur.size()); k++) cur[k] = k;
  }
  cycle(const vector<int>& v) { cur = v; }
  cycle(const cycle& c) { cur = c.cur; }
  cycle operator*(const cycle& oth) {
    cycle ans(cur.size());
    for (int k = 0; k < (cur.size()); k++) ans.cur[k] = cur[oth.cur[k]];
    return ans;
  }
  cycle power(int T) const {
    cycle v = *this, ans(cur.size());
    while (T) {
      if (T & 1) ans = ans * v;
      v = v * v;
      T >>= 1;
    }
    return ans;
  }
};
cycle D_sort(int n, int d, int L) {
  cycle ans;
  for (int i = 0; i < (d); i++)
    for (int j = i; j < L; j += d) ans.cur.push_back(j);
  for (int k = L; k < n; k++) ans.cur.push_back(k);
  return ans;
}
cycle hd_to_bk(int n, int l) {
  cycle ans;
  for (int k = 0; k < (n - l); k++) ans.cur.push_back(l + k);
  for (int k = 0; k < (l); k++) ans.cur.push_back(k);
  return ans;
}
char S[1000005], S2[100005];
int main() {
  int n, m, c, d;
  gets(S);
  n = strlen(S);
  scanf("%d", &m);
  for (int k = 0; k < (m); k++) {
    scanf("%d%d", &c, &d);
    cycle C = (D_sort(n, d, c) * hd_to_bk(n, 1)).power(n + 1 - c) *
              hd_to_bk(n, c - 1);
    for (int k = 0; k < (n); k++) S2[k] = S[C.cur[k]];
    for (int k = 0; k < (n); k++) S[k] = S2[k];
    puts(S);
  }
  return 0;
}
