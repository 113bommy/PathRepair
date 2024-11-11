#include <bits/stdc++.h>
using namespace std;
long long dp[(int)1e6 + 20];
long long dr[(int)1e6 + 20];
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string str;
  cin >> str;
  int jj = 0;
  int len = str.length();
  vector<int> V;
  long long k = 0;
  long long p = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == '1') {
      V.push_back(i);
      dp[i] = jj;
      jj = 0;
      int f = 1;
      while (p - f + 1) {
        k += (p - f + 1);
        f++;
      }
      p = 0;
    } else {
      jj++;
      p++;
    }
  }
  int f = 1;
  while (p - f + 1) {
    k += (p - f + 1);
    f++;
  }
  p = 0;
  jj = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (str[i] == '1') {
      dr[i] = jj;
      jj = 0;
    } else {
      jj++;
    }
  }
  long long s = 0;
  n--;
  for (int i = 0; i < (int)V.size(); i++) {
    if (i + n >= (int)V.size() || n + i < 0) break;
    s += (1 + dp[V[i]]) * (1 + dr[V[i + n]]);
  }
  if (n >= 0)
    cout << s;
  else
    cout << k;
  return 0;
}
