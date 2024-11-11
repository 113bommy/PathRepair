#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
template <typename T>
inline void printVector(const T& a, int type = 0, int left = -1,
                        int right = -1) {
  if (left != -1 && right != -1) {
    for (int i = left; i < right; i++) {
      cout << a[i] << " ";
      if (type == 1) {
        cout << endl;
      }
    }
    if (type == 0) {
      cout << endl;
    }
    return;
  }
  for (auto it : a) {
    cout << it << " ";
    if (type == 1) {
      cout << endl;
    }
  }
  if (type == 0) {
    cout << endl;
  }
}
template <typename T>
inline void printPairVector(const T& a, int left = -1, int right = -1) {
  if (left != -1 && right != -1) {
    for (int i = left; i < right; i++) {
      cout << a[i].first << " " << a[i].second << endl;
    }
    return;
  }
  for (auto it : a) {
    cout << it.first << " " << it.second << endl;
  }
}
int powTen[20], bitCount[1 << 10];
int k;
int mul(long long a, long long b) { return (a * b) % mod; }
int add(long long a, long long b) {
  a += b;
  a %= mod;
  if (a < 0) {
    a += mod;
  }
  return a;
}
int getBits(int n) {
  int ans = 0;
  while (n > 0) {
    if (n & 1) {
      ans++;
    }
    n >>= 1;
  }
  return ans;
}
pair<long long, int> dp[20][1 << 10][2];
int cal(string s) {
  memset(dp, 0, sizeof(dp));
  dp[0][0][1].first = 1;
  int len = s.size();
  int i, mask, dig;
  for (i = 0; i < len; i++) {
    int curDig = (int)(s[i] - '0');
    for (mask = 0; mask < (1 << 10); mask++) {
      if (dp[i][mask][0].first == 0 && dp[i][mask][1].first == 0) {
        continue;
      }
      for (dig = (int)(i == 0); dig <= 9; dig++) {
        int newMask = mask | (1 << dig);
        dp[i + 1][newMask][0].first += dp[i][mask][0].first;
        dp[i + 1][newMask][0].second =
            add(add(dp[i][mask][0].second,
                    mul(mul(powTen[len - i - 1], dp[i][mask][0].first), dig)),
                dp[i + 1][newMask][0].second);
      }
      for (dig = (int)(i == 0); dig <= curDig; dig++) {
        int newMask = mask | (1 << dig);
        dp[i + 1][newMask][(int)(dig == curDig)].first += dp[i][mask][1].first;
        dp[i + 1][newMask][(int)(dig == curDig)].second =
            add(add(dp[i][mask][1].second,
                    mul(mul(powTen[len - i - 1], dp[i][mask][1].first), dig)),
                dp[i + 1][newMask][(int)(dig == curDig)].second);
      }
    }
  }
  int ans = 0;
  for (i = 0; i < (1 << 10); i++) {
    if (bitCount[i] > k) {
      continue;
    }
    ans = add(ans, dp[len][i][0].second);
    ans = add(ans, dp[len][i][1].second);
  }
  return ans;
}
int solve(long long number) {
  string s = to_string(number);
  int len = s.size();
  int ans = 0;
  for (int i = 1; i < len; i++) {
    string t = string(i, '9');
    ans = add(ans, cal(t));
  }
  ans = add(ans, cal(s));
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long l, r;
  cin >> l >> r >> k;
  int i;
  powTen[0] = 1;
  for (i = 1; i < 20; i++) {
    powTen[i] = mul(powTen[i - 1], 10);
  }
  for (i = 0; i < (1 << 10); i++) {
    bitCount[i] = getBits(i);
  }
  cout << add(solve(r), -solve(l - 1));
  return 0;
}
