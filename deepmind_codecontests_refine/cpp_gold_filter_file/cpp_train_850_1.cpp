#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long bc = n;
  for (long long i = 0; i < n - 1; ++i) {
    if (s[i] != s[i + 1]) bc += 1;
  }
  long long dp1[n];
  for (long long i = n - 1; i >= 0; --i) {
    if (i == n - 1) {
      dp1[i] = 1;
      continue;
    }
    if (s[i] == s[i + 1]) {
      dp1[i] = 1 + dp1[i + 1];
    } else
      dp1[i] = 1;
  }
  long long dp2[n];
  for (long long i = 0; i < n; ++i) {
    if (i == 0) {
      dp2[i] = 1;
      continue;
    }
    if (s[i] == s[i - 1]) {
      dp2[i] = 1 + dp2[i - 1];
    } else
      dp2[i] = 1;
  }
  for (long long i = 0; i < n - 1; ++i) {
    if (s[i] != s[i + 1]) {
      if (dp1[i + 1] >= 2) {
        bc += (dp1[i + 1] - 1);
      }
    }
  }
  for (long long i = n - 1; i > 0; --i) {
    if (s[i] != s[i - 1]) {
      if (dp2[i - 1] >= 2) {
        bc += (dp2[i - 1] - 1);
      }
    }
  }
  cout << (n * (n + 1)) / 2 - bc;
  return 0;
}
