#include <bits/stdc++.h>
using namespace std;
const int N = 1314520;
const long long MOD = 1e9 + 7;
int oldArr[N], newArr[N];
template <class T>
inline void AddWithMod(T &a, const T &b) {
  a += b;
  a %= MOD;
}
int main() {
  long long n, l, k;
  while (cin >> n >> l >> k) {
    vector<vector<long long> > dp(k + 1, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
      scanf("%d", oldArr + i);
      newArr[i] = oldArr[i];
    }
    if (l <= n) {
      cout << l << endl;
      continue;
    }
    long long r = l % n;
    sort(newArr, newArr + n);
    sort(oldArr, oldArr + r);
    long long c = l / n;
    long long answer = l % MOD;
    cerr << "c " << c << endl;
    for (int i = 0; i < n; ++i) {
      dp[1][i] = 1;
    }
    for (int i = 2; i <= k; ++i) {
      long long sum, sum2;
      sum = sum2 = 0;
      for (int j = 0, t = 0; j < n; ++j) {
        while (t < n && newArr[t] <= newArr[j]) {
          AddWithMod(sum, dp[i - 1][t]);
          ++t;
        }
        dp[i][j] = sum;
        AddWithMod(sum2, sum);
      }
      answer = (answer + sum2 * max(0LL, c - i + 1)) % MOD;
      if (c - i + 1 >= 0) {
        sum = 0;
        for (int j = 0, t = 0; j < r; ++j) {
          while (t < n && newArr[t] <= oldArr[j]) {
            AddWithMod(sum, dp[i - 1][t]);
            ++t;
          }
          AddWithMod(answer, sum);
        }
      }
    }
    cout << answer << endl;
  }
  return 0;
}
