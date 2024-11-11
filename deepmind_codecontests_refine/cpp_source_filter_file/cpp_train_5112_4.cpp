#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
using namespace std::chrono;
stack<long long int> st;
int main() {
  long long int n, val, x;
  cin >> n;
  vector<long long int> vec(n + 1, 0);
  long long int dp[n + 1][5];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) cin >> vec[i];
  dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 1;
  for (int i = 1; i < n; i++) {
    if (vec[i - 1] < vec[i]) {
      for (int j = 0; j < 5; j++) {
        if (dp[i - 1][j]) {
          for (int k = j + 1; k < 5; k++) dp[i][k] = 1;
        }
      }
    } else if (vec[i - 1] == vec[i]) {
      for (int j = 0; j < 5; j++) {
        if (dp[i - 1][j]) {
          for (int k = j + 1; k < 5; k++) dp[i][k] = 1;
        }
      }
      for (int j = 0; j < 5; j++) {
        if (dp[i - 1][j]) {
          for (int k = j - 1; k >= 0; k--) dp[i][k] = 1;
        }
      }
    } else {
      for (int j = 0; j < 5; j++) {
        if (dp[i - 1][j]) {
          for (int k = j - 1; k >= 0; k--) dp[i][k] = 1;
        }
      }
    }
  }
  if (dp[n - 1][0])
    st.push(0);
  else if (dp[n - 1][1])
    st.push(1);
  else if (dp[n - 1][2])
    st.push(2);
  else if (dp[n - 1][3])
    st.push(3);
  else if (dp[n - 1][4])
    st.push(4);
  if (st.empty()) {
    cout << -1;
    return 0;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (vec[i] < vec[i + 1]) {
      val = st.top();
      x = val - 1;
      while (x >= 0) {
        if (dp[i][x] == 1) {
          st.push(x);
          break;
        } else
          x--;
      }
    } else if (vec[i] == vec[i - 1]) {
      bool flag2 = 1;
      val = st.top();
      x = val - 1;
      while (x >= 0) {
        if (dp[i][x] == 1) {
          st.push(x);
          flag2 = 0;
          break;
        } else
          x--;
      }
      x = val + 1;
      while (x < 5 && flag2) {
        if (dp[i][x] == 1) {
          st.push(x);
          flag2 = 0;
          break;
        } else
          x++;
      }
    } else {
      val = st.top();
      x = val + 1;
      while (x < 5) {
        if (dp[i][x] == 1) {
          st.push(x);
          break;
        } else
          x++;
      }
    }
  }
  long long int ctr = 0;
  while (!st.empty()) {
    cout << st.top() + 1 << " ";
    st.pop();
    ctr++;
  }
  return 0;
}
