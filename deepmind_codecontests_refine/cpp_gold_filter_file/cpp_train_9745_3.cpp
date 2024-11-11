#include <bits/stdc++.h>
using namespace std;
int data[(int)2e5];
int dp[5001][5001];
int used[5001][5001];
string s;
int magic(int l, int r) {
  if (l > r) return 1;
  if (used[l][r] != -1) return used[l][r];
  if (l == r) {
    data[1]++;
    return used[l][r] = 1;
  }
  int lk, rk, k, flag = 1, middle = (l + r) / 2;
  lk = magic(l, (r - l) % 2 == 0 ? (middle - 1) : middle);
  rk = magic(middle + 1, r);
  k = min(lk, rk) + 1;
  if (s[l] == s[r] and magic(l + 1, r - 1)) {
    for (int i = 1; i <= k; i++) data[i]++;
    return used[l][r] = k;
  }
  return used[l][r] = 0;
}
int main() {
  memset(used, -1, sizeof(used));
  cin >> s;
  int n = s.size() - 1;
  for (int i = 0; i <= n; i++) {
    for (int j = i; j <= n; j++) magic(i, j);
  }
  for (int i = 1; i <= s.size(); i++) cout << data[i] << " ";
  return 0;
}
