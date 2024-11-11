#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const int N = 2e5 + 1;
const int B = 448;
const int B1 = 448;
long long firki = 0, wowsum = 0;
int bit[N], pos[N], x, n, tot, before[N], after[N], aftersum[B1], beforesum[B1],
    afterlazy[B1], beforelazy[B1], mindiff[B1];
bool done[N], issaok;
short donebl[B1];
inline void upd(int ind, int x) {
  while (ind <= n) {
    bit[ind] += x;
    ind += (ind & (-ind));
  }
}
inline int suma(int ind) {
  int res = 0;
  while (ind) {
    res += bit[ind];
    ind -= ind & (-ind);
  }
  return res;
}
inline void resetblock(int which, int pos) {
  aftersum[which] = beforesum[which] = 0;
  mindiff[which] = INF;
  for (int i = which * B; i < min(n, (which + 1) * B); i++) {
    if (done[i]) continue;
    before[i] += beforelazy[which] + (pos < i);
    after[i] += afterlazy[which] + (pos > i);
    if (i == pos) {
      done[pos] = 1;
      donebl[which]++;
      before[i] = after[i] = 0;
    } else {
      mindiff[which] = min(mindiff[which], after[i] - before[i]);
      aftersum[which] += after[i];
      beforesum[which] += before[i];
    }
  }
  beforelazy[which] = afterlazy[which] = 0;
}
inline long long normalreset(int which) {
  long long res = 0;
  int c1 = beforelazy[which];
  int c2 = afterlazy[which];
  for (int i = which * B; i < min(n, (which + 1) * B); i++) {
    if (done[i]) continue;
    res += min(before[i] + c1, after[i] + c2);
  }
  return res;
}
inline void normalupdate(int which, int pos) {
  int blsize = min(B, n - which * B);
  if (pos > which * B) {
    afterlazy[which]++;
    aftersum[which] += (blsize - donebl[which]);
    mindiff[which]++;
  } else {
    beforelazy[which]++;
    beforesum[which] += (blsize - donebl[which]);
    mindiff[which]--;
  }
}
void solve() {
  cin >> n;
  tot = (n - 1) / B + 1;
  for (int j = 0; j < tot; j++) {
    mindiff[j] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> x;
    pos[x] = i - 1;
  }
  for (int i = 1; i <= n; i++) {
    firki += (i - 1) - suma(pos[i]);
    upd(pos[i] + 1, 1);
    for (int j = 0; j < tot; j++) {
      if (pos[i] / B == j) {
        resetblock(j, pos[i]);
      } else {
        normalupdate(j, pos[i]);
      }
    }
    issaok = 0;
    wowsum = 0;
    for (int j = 0; j < tot; j++) {
      if (mindiff[j] < 0 and !issaok) {
        wowsum += normalreset(j);
        issaok = 1;
      } else {
        if (issaok)
          wowsum += aftersum[j];
        else
          wowsum += beforesum[j];
      }
    }
    cout << firki + wowsum << " ";
  }
}
int main() {
  solve();
  return 0;
}
