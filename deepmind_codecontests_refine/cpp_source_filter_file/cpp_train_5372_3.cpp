#include <bits/stdc++.h>
using namespace std;
const int INF = 522133279;
const int MAXN = 100000;
const int TOTN = 100 + 100;
const long long MOD = 1000000007;
bool _su[MAXN];
vector<int> su;
vector<int> suc;
int n, k;
void shai() {
  memset((_su), true, sizeof(_su));
  for (int i = (2); i < (MAXN); i++) {
    if (k <= 1) break;
    if (_su[i] && k % i == 0) {
      su.push_back(i);
      suc.push_back(0);
      while (k && k % i == 0) {
        k /= i;
        suc.back()++;
      }
      for (int j = 2; j * i < MAXN; j++) _su[j * i] = false;
    }
  }
  if (k != 1) {
    su.push_back(k);
    suc.push_back(1);
  }
}
vector<int> fen(int x) {
  vector<int> cnt;
  cnt.resize(su.size());
  for (int i = (0); i < (su.size()); i++) {
    while (x && x % su[i] == 0) {
      x /= su[i];
      cnt[i]++;
    }
  }
  return cnt;
}
vector<vector<int> > lis;
bool divisible(vector<int> cnt) {
  bool ok = true;
  for (int i = (0); i < (cnt.size()); i++) {
    if (cnt[i] < suc[i]) {
      ok = false;
      break;
    }
  }
  return ok;
}
vector<int> getCnt(int l, int r) {
  if (l == 0) return lis[r];
  vector<int> res;
  for (int i = (0); i < (lis[l].size()); i++) {
    res.push_back(lis[r][i] - lis[l - 1][i]);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  shai();
  for (int i = (0); i < (n); i++) {
    int a;
    cin >> a;
    lis.push_back(fen(a));
  }
  for (int i = (1); i < (n); i++) {
    for (int j = (0); j < (lis[i].size()); j++) {
      lis[i][j] += lis[i - 1][j];
    }
  }
  int l = 0, r = 0;
  int ans = 0;
  while (r < n) {
    while (r < n && !divisible(getCnt(l, r))) r++;
    if (r >= n) break;
    ans += n - r;
    l++;
    if (l > r) r = l;
  }
  cout << ans << endl;
  return 0;
}
