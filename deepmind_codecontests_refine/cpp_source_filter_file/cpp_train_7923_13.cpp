#include <bits/stdc++.h>
using namespace std;
const int MAXN = 16 + 1;
int n, m;
long long y;
vector<int> bigger[MAXN];
vector<int> smaller[MAXN];
int pref;
bool used[MAXN];
int res[MAXN];
bool checkWithPrefix(int pos, int j) {
  for (int k = 0; k < bigger[pos].size(); k++) {
    int i = bigger[pos][k];
    if (i >= pref) continue;
    if (res[i] < j) return false;
  }
  for (int k = 0; k < smaller[pos].size(); k++) {
    int i = smaller[pos][k];
    if (i >= pref) continue;
    if (res[i] > j) return false;
  }
  return true;
}
bool isBitSet(int bit, int mask) { return (mask & (1 << bit)) > 0; }
bool checkWithSuffix(int pos, int usedPositions) {
  for (int i = 0; i < bigger[pos].size(); i++) {
    int j = bigger[pos][i];
    if (isBitSet(j, usedPositions)) return false;
  }
  return true;
}
int setBit(int bit, int mask) { return mask | (1 << bit); }
long long memo[MAXN + 1][1 << (MAXN + 1)];
long long f(int e, int usedPositions) {
  if (e == n) return 1;
  long long &res = memo[e][usedPositions];
  if (res != -1) return res;
  res = 0;
  if (used[e])
    res = f(e + 1, usedPositions);
  else {
    for (int pos = pref + 1; pos < n; pos++) {
      if (isBitSet(pos, usedPositions)) continue;
      if (!checkWithPrefix(pos, e)) continue;
      if (!checkWithSuffix(pos, usedPositions)) continue;
      res += f(e + 1, setBit(pos, usedPositions));
    }
  }
  return res;
}
long long g() {
  memset(memo, -1, sizeof(memo));
  return f(0, 0);
}
int main() {
  scanf("%d %I64d %d", &n, &y, &m);
  y -= 2000;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    smaller[b].push_back(a);
    bigger[a].push_back(b);
  }
  for (int i = 0; i < m; i++) used[i] = false;
  pref = -1;
  long long all = g();
  if (all < y) {
    printf("The times have changed\n");
    return 0;
  }
  for (pref = 0; pref < n; pref++) {
    for (int j = 0; j < n; j++) {
      res[pref] = j;
      if (used[j]) continue;
      used[j] = true;
      if (checkWithPrefix(pref, j)) {
        long long num = g();
        if (num >= y) break;
        y -= num;
      }
      used[j] = false;
    }
  }
  for (int i = 0; i < n; i++) printf("%d ", res[i] + 1);
  printf("\n");
}
