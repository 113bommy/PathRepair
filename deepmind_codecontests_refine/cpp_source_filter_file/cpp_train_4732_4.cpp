#include <bits/stdc++.h>
using namespace std;
int primes[20] = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                  29, 31, 37, 41, 43, 47, 53, 59};
vector<vector<int> > adj(100), badj(100), lol(100);
int dp[20][(1 << 17) + 10];
int par[20][(1 << 17) + 10], a[120], b[120];
int check(int mask, int val) {
  int i, haha;
  for (i = 0; i < lol[val].size(); i++) {
    haha = (1 << lol[val][i]);
    if (mask & haha) {
      return -1;
    } else {
      mask |= haha;
    }
  }
  return mask;
}
int compute(int n, int mask) {
  if (n == -1) return 0;
  if (dp[n][mask] != -1) return dp[n][mask];
  int i, maxi = 0, val;
  for (i = 0; i < n; i++) {
    maxi += b[i] - 1;
  }
  val = 1;
  int value;
  for (i = 2; i < 60; i++) {
    int new_mask = check(mask, i);
    if (new_mask != -1) {
      value = abs(b[n] - i) + compute(n - 1, new_mask);
      if (value < maxi) {
        maxi = value;
        val = i;
      }
    }
  }
  par[n][mask] = val;
  dp[n][mask] = maxi;
  return dp[n][mask];
}
int answ[120];
int main() {
  std::ios::sync_with_stdio(false);
  int n, i, j;
  cin >> n;
  int maama = n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    adj[a[i]].push_back(i);
  }
  for (i = 0; i < 17; i++) {
    for (j = 2; j < 61; j++) {
      if (j % primes[i] == 0) {
        lol[j].push_back(i);
      }
    }
    for (j = 0; j < (1 << 17) + 5; j++) {
      dp[i][j] = -1;
    }
  }
  sort(a, a + n);
  for (i = 0; i < max(n - 17, 0); i++) {
    badj[a[i]].push_back(1);
  }
  j = 0;
  for (i = max(n - 17, 0); i < n; i++) {
    b[j] = a[i];
    j++;
  }
  compute(min(16, n - 1), 0);
  n = min(16, n - 1);
  int mask = 0;
  while (n >= 0) {
    answ[n] = par[n][mask];
    if (answ[n] == 1) {
      for (i = 0; i < n; i++) {
        answ[i] = 1;
      }
      break;
    }
    mask = check(mask, par[n][mask]);
    n--;
  }
  for (i = 0; i < min(17, maama); i++) {
    badj[b[i]].push_back(answ[i]);
  }
  for (i = 0; i < 32; i++) {
    for (j = 0; j < adj[i].size(); j++) {
      answ[adj[i][j]] = badj[i][j];
    }
  }
  for (i = 0; i < maama; i++) {
    cout << answ[i] << " ";
  }
}
