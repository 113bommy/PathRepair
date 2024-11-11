#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100000 + 5;
int n, x[MAX_N], dpMin[MAX_N][8], dpMax[MAX_N][8];
int dir[] = {-1, 0, 1};
pair<int, int> rec(int i, int mask) {
  if (i > n) return {0, 0};
  if (dpMax[i][mask] != -1) return {dpMin[i][mask], dpMax[i][mask]};
  int prv = x[i - 1], cur = x[i];
  int pa = (mask & 4) ? prv - 1 : -1;
  int pb = (mask & 2) ? prv : -1;
  int pc = (mask & 1) ? prv + 1 : -1;
  int cma = (cur - 1 == pa || cur - 1 == pb || cur - 1 == pc) ? 4 : 0;
  int cmb = (cur == pa || cur == pb || cur == pc) ? 2 : 0;
  int cmc = (cur + 1 == pa || cur + 1 == pb || cur + 1 == pc) ? 1 : 0;
  dpMin[i][mask] = MAX_N;
  dpMax[i][mask] = 0;
  pair<int, int> tmp = rec(i + 1, 4 | cmb | cmc);
  dpMin[i][mask] = min(dpMin[i][mask], !cma + tmp.first);
  dpMax[i][mask] = max(dpMax[i][mask], !cma + tmp.second);
  tmp = rec(i + 1, cma | 2 | cmc);
  dpMin[i][mask] = min(dpMin[i][mask], !cmb + tmp.first);
  dpMax[i][mask] = max(dpMax[i][mask], !cmb + tmp.second);
  tmp = rec(i + 1, cma | cmb | 1);
  dpMin[i][mask] = min(dpMin[i][mask], !cmc + tmp.first);
  dpMax[i][mask] = max(dpMax[i][mask], !cmc + tmp.second);
  return {dpMin[i][mask], dpMax[i][mask]};
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  sort(x + 1, x + n + 1);
  memset(dpMin, -1, sizeof(dpMin));
  memset(dpMax, -1, sizeof(dpMax));
  pair<int, int> res = rec(1, 0);
  cout << res.first << ' ' << res.second << endl;
  return 0;
}
