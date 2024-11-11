#include <bits/stdc++.h>
using namespace std;
long long dpl[700][2] = {0}, dpr[700][2] = {0};
int main() {
  string s;
  cin >> s;
  stack<int> st;
  vector<int> v;
  vector<int> vo;
  vector<bool> c;
  for (int i = 0; i < s.length(); i++) {
    int temp = i;
    if (s[i] == '(')
      st.push(i);
    else {
      temp = st.top();
      st.pop();
    }
    v.push_back(temp);
    vo.push_back(i);
    vo[temp] = i;
    if (st.empty())
      c.push_back(true);
    else
      c.push_back(false);
  }
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') continue;
    int l = v[i], r = i;
    if (l + 1 == r) {
      for (int j = 0; j < 2; j++) {
        dpl[l][j] = 1;
        dpr[l][j] = 1;
      }
    } else {
      long long dp[3][3] = {0};
      for (int j = 0; j < 2; j++) dp[2][j] = dpr[l + 1][j];
      for (int j = 0; j < 2; j++) dp[j][2] = dpl[l + 1][j];
      int q = vo[l + 1] + 1;
      while (q < r) {
        long long ndp[3][3] = {0};
        for (int j = 0; j < 3; j++)
          for (int k = 0; k < 3; k++)
            for (int y = 0; y < 2; y++) {
              if (k != y)
                ndp[j][2] = (ndp[j][2] + dpl[q][y] * dp[j][k]) % 1000000007;
              ndp[j][y] = (ndp[j][y] + dp[j][k] * dpr[q][y]) % 1000000007;
            }
        for (int j = 0; j < 3; j++)
          for (int k = 0; k < 3; k++) dp[j][k] = ndp[j][k];
        q = vo[q] + 1;
      }
      for (int j = 0; j < 2; j++) {
        long long d = 0;
        for (int k = 0; k < 3; k++)
          for (int y = 0; y < 3; y++)
            if (j != k) d = (d + dp[k][y]) % 1000000007;
        dpl[l][j] = d;
      }
      for (int j = 0; j < 2; j++) {
        long long d = 0;
        for (int k = 0; k < 3; k++)
          for (int y = 0; y < 3; y++)
            if (j != y) d = (d + dp[k][y]) % 1000000007;
        dpr[l][j] = d;
      }
    }
  }
  long long dp[3];
  dp[2] = 1;
  for (int i = 0; i < s.length(); i++) {
    if (c[i]) {
      int l = v[i];
      long long ndp[3] = {0};
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 3; k++)
          ndp[j] = (ndp[j] + dp[k] * dpr[l][j]) % 1000000007;
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 3; k++)
          if (j != k) ndp[2] = (ndp[2] + dp[k] * dpl[l][j]) % 1000000007;
      for (int j = 0; j < 3; j++) dp[j] = ndp[j];
    }
  }
  cout << (dp[0] + dp[1] + dp[2]) % 1000000007;
}
