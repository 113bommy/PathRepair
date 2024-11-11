#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
bool comps(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}
bool prime[1000005];
void primeseries(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
struct custom_hash {
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    x ^= FIXED_RANDOM;
    return x ^ (x >> 16);
  }
};
bool compmx(int a, int b) { return (a < b); }
void fastio() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
void inout() {}
bool chk(string a) {
  int cnt = 0;
  bool flag = true;
  for (int i = 0; i < (a).size(); i++) {
    if (a[i] == '(')
      cnt++;
    else if (a[i] == ')')
      cnt--;
    else
      flag = false;
    if (cnt < 0) flag = false;
  }
  if (cnt != 0) flag = false;
  return flag;
}
int n, k;
string a[2005];
string st[] = {"1110111", "0010010", "1011101", "1011011", "0111010",
               "1101011", "1101111", "1010010", "1111111", "1111011"};
int change[2005][10];
int dp[2005][2005][10];
void chng() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      int x = 0;
      for (int q = 0; q < 7; q++) {
        if (a[i][q] != st[j][q] && a[i][q] == '0') {
          x++;
        } else if (a[i][q] != st[j][q]) {
          goto nxt;
        }
      }
      change[i][j] = x;
    nxt:
      x = 0;
    }
  }
}
int makeme(int r, int k, int dig) {
  if (r == n) {
    if (k == 0)
      return dp[r][k][dig] = 1;
    else
      return dp[r][k][dig] = 0;
  } else if (k <= 0)
    return dp[r][k][dig] = 0;
  else if (dp[r][k][dig] != -1)
    return dp[r][k][dig];
  int x = 0;
  for (int i = 0; i < 10; i++) {
    if (change[r][i] != -1) x = max(x, makeme(r + 1, k - change[r][i], i));
  }
  dp[r][k][dig] = x;
  return dp[r][k][dig];
}
string s;
void makemystr(int r, int k) {
  if (r == n) return;
  for (int i = 9; i >= 0; i += -1) {
    if (k - change[r][i] >= 0 && dp[r + 1][k - change[r][i]][i] == 1) {
      s.push_back('0' + i);
      makemystr(r + 1, k - change[r][i]);
      return;
    }
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(change, -1, sizeof(change));
  chng();
  memset(dp, -1, sizeof(dp));
  makeme(0, k, 0);
  makemystr(0, k);
  if ((s).size())
    cout << s;
  else
    cout << -1;
  return 0;
}
