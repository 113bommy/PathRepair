#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int pow(long long int base, long long int po,
                  long long int mod = 1000000007) {
  long long int ret = 1;
  while (po) {
    if (po % 2) {
      ret = (ret * base) % 1000000007;
    }
    base = (base * base) % 1000000007;
    po /= 2;
  }
  return ret;
}
long long int invMod(long long int val) {
  return pow(val, 1000000007 - 2, 1000000007);
}
int dp[5002][5002];
int main() {
  int n, c;
  cin >> n;
  vector<int> vec;
  int sz = 0;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (i == 0 || vec[sz - 1] != c) {
      sz++;
      vec.push_back(c);
    }
  }
  for (int i = 0; i < 5002; i++) {
    for (int j = 0; j < 5002; j++) dp[i][j] = 0;
  }
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j + i < sz; j++) {
      int k = j + i;
      if (i == 0) {
        dp[j][k] = 1;
      } else {
        if (vec[j] == vec[k]) {
          dp[j][k] = dp[j + 1][k - 1] + 2;
        } else {
          dp[j][k] = max(dp[j + 1][k], dp[j][k - 1]);
        }
      }
    }
  }
  cout << sz - (dp[0][sz - 1] + 1) / 2 << endl;
}
