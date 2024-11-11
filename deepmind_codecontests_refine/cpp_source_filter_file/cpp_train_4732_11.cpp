#include <bits/stdc++.h>
using namespace std;
int n;
int num[100 + 10];
int memo[100 + 10][1 << 17];
int visit[100 + 10][1 << 17];
vector<int> fact[60];
int prime[17] = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                 29, 31, 37, 39, 41, 43, 47, 53};
map<int, int> ind;
int REC(int p, int mask) {
  if (p == n) return 0;
  if (~memo[p][mask]) return memo[p][mask];
  int res = 1000000000, a = 1000000000, b = 1000000000, tmp, g;
  a = REC(p + 1, mask | 1) + abs(num[p] - 1);
  for (int i = 2; i < 59; i++) {
    bool flag = 1;
    int newmask = 0;
    for (int j = 0; j < (int)fact[i].size(); j++) {
      int z = ind[fact[i][j]];
      if (mask & (1 << z)) {
        flag = 0;
        break;
      } else
        newmask |= (1 << z);
    }
    if (flag) {
      tmp = REC(p + 1, mask | newmask) + abs(num[p] - i);
      if (tmp < b) {
        b = tmp;
        g = i;
      }
    }
  }
  if (a <= b) {
    res = a;
    visit[p][mask] = 1;
  } else {
    res = b;
    visit[p][mask] = g;
  }
  return memo[p][mask] = res;
}
void factor(int x) {
  int f = 2, xx = x;
  while (f * f <= x) {
    bool flag = 0;
    while (x % f == 0) x /= f, flag = 1;
    if (flag) fact[xx].push_back(f);
    f++;
  }
  if (x > 1) fact[xx].push_back(x);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  memset((memo), (-1), sizeof(memo));
  for (int i = 2; i < 59; i++) {
    factor(i);
  }
  for (int i = 0; i < 17; i++) {
    ind[prime[i]] = i + 1;
  }
  REC(0, 0);
  vector<int> ans;
  int p = 0, mask = 0;
  while (p < n) {
    int nxt = visit[p][mask];
    ans.push_back(nxt);
    if (nxt == 1)
      mask |= 1;
    else {
      for (int i = 0; i < (int)fact[nxt].size(); i++) {
        int z = ind[fact[nxt][i]];
        mask |= (1 << z);
      }
    }
    p++;
  }
  for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
