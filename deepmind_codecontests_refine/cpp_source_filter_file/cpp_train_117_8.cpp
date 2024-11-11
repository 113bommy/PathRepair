#include <bits/stdc++.h>
using namespace std;
set<long long int> s[100005];
long long int d[100005];
vector<char> prime(100000 + 1, true);
void sieve(long long int n) {
  prime[0] = prime[1] = false;
  for (long long int i = 2; i <= n; ++i) {
    if (prime[i]) {
      s[i].insert(i);
      for (long long int j = 2 * i; j <= n; j += i) {
        prime[j] = false;
        s[j].insert(i);
      }
    }
  }
}
void init(long long int ar[], long long int n, long long int val) {
  long long int i;
  for (i = 0; i < n; i++) {
    ar[i] = val;
  }
}
long long int search1(vector<long long int> &v, long long int f) {
  long long int left = 0;
  long long int right = v.size() - 1;
  while (left < right) {
    long long int mid = left + (right - left + 1) / 2;
    if (v[mid] <= f) {
      left = mid;
    } else
      right = mid - 1;
  }
  return left;
}
int main() {
  long long int n, k, i, j;
  cin >> n;
  long long int dp[n + 1][10];
  for (i = 0; i <= n; i++) {
    for (j = 0; j < 10; j++) {
      dp[i][j] = -1000000000;
    }
  }
  dp[0][0] = 0;
  long long int t = n;
  for (i = 1; i <= n; i++) {
    cin >> k;
    long long int c1, d;
    long long int a1 = 0, a2 = 0, a3 = 0, b = 0, c = 0;
    for (j = 0; j < k; j++) {
      cin >> c1 >> d;
      if (c1 == 2) {
        b = max(b, d);
      } else if (c1 == 3) {
        c = max(c, d);
      } else {
        if (d >= a1) {
          a3 = a2;
          a2 = a1;
          a1 = d;
        } else if (d >= a2) {
          a3 = a2;
          a2 = d;
        } else if (d >= a3) {
          a3 = d;
        }
      }
    }
    long long int maxs = max(a1, b);
    long long int mins = min(a1, b);
    if (i == 1) {
      dp[1][0] = 0;
      if (c != 0) {
        dp[1][1] = max(c, dp[1][1]);
      }
      if (a1 != 0) {
        dp[1][1] = max(dp[1][1], a1);
      }
      if (b != 0) {
        dp[1][1] = max(dp[1][1], b);
      }
      if (a1 != 0 && b != 0) {
        dp[1][2] = max(dp[1][2], maxs + mins);
      }
      if (a2 != 0) {
        dp[1][2] = max(a1 + a2, dp[1][2]);
      }
      if (a3 != 0) {
        dp[1][3] = a1 + a2 + a3;
      }
      continue;
    }
    for (j = 0; j < 10; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      long long int val = c;
      if (j == 0) val += c;
      if (c != 0) dp[i][j] = max(dp[i][j], val + dp[i - 1][(j - 1 + 10) % 10]);
      if (a3 != 0) {
        val = a1 + a2 + a3;
        if (j < 3) val += a1;
        dp[i][j] = max(dp[i][j], val + dp[i - 1][(j - 3 + 10) % 10]);
      }
      if (a2 != 0) {
        val = a1 + a2;
        if (j < 2) val += a1;
        dp[i][j] = max(dp[i][j], val + dp[i - 1][(j - 2 + 10) % 10]);
      }
      if (a1 != 0) {
        val = a1;
        if (j < 1) val += a1;
        dp[i][j] = max(dp[i][j], val + dp[i - 1][(j - 1 + 10) % 10]);
      }
      if (b != 0) {
        val = b;
        if (j < 1) val += b;
        dp[i][j] = max(dp[i][j], val + dp[i - 1][(j - 1 + 10) % 10]);
      }
      if (maxs != 0 && mins != 0) {
        val = maxs + mins;
        if (j < 2) val += maxs;
        dp[i][j] = max(dp[i][j], val + dp[i - 1][(j - 2 + 10) % 10]);
      }
    }
  }
  cout << *max_element(dp[n], dp[n] + 10) << endl;
  return 0;
}
