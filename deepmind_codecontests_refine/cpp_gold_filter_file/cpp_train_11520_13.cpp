#include <bits/stdc++.h>
using namespace std;
long long barr[100100], freq[100100], stree[400100][2];
long long query(long long strt, long long ed, long long qs, long long qe,
                long long ind, bool flag) {
  if (qs > qe || strt > ed || qs > ed || qe < strt) return 0;
  if (qs <= strt && qe >= ed) return stree[ind][flag];
  long long mid = (strt + ed) / 2;
  return max(query(strt, mid, qs, qe, ind * 2 + 1, flag),
             query(mid + 1, ed, qs, qe, ind * 2 + 2, flag));
}
void update(long long strt, long long ed, long long i, long long v,
            long long ind, bool flag) {
  if (strt > i || ed < i) return;
  if (strt == ed) {
    stree[ind][flag] = v;
    return;
  }
  long long mid = (strt + ed) / 2;
  update(strt, mid, i, v, ind * 2 + 1, flag);
  update(mid + 1, ed, i, v, ind * 2 + 2, flag);
  stree[ind][flag] = max(stree[ind * 2 + 1][flag], stree[ind * 2 + 2][flag]);
}
long long lis[100100], lds[100100];
int main() {
  long long n, m, i, j, k, l;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> j >> k;
    barr[j]++;
    barr[k + 1]--;
  }
  long long sum = 0;
  for (i = 1; i <= m; i++) {
    sum += barr[i];
    freq[i] = sum;
  }
  for (i = 1; i <= m; i++) {
    lis[i] = query(0, n, 0, freq[i], 0, 0) + 1;
    update(0, n, freq[i], lis[i], 0, 0);
  }
  for (i = m; i >= 1; i--) {
    lds[i] = query(0, n, 0, freq[i], 0, 1) + 1;
    update(0, n, freq[i], lds[i], 0, 1);
  }
  long long ans = 0;
  for (i = 1; i <= m; i++) {
    ans = max(ans, lis[i] + lds[i] - 1);
  }
  cout << ans << '\n';
  return 0;
}
