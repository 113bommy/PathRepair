#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100 * 1000 + 5;
string s;
int n, pAr[Maxn], dp[Maxn], dp2[Maxn];
vector<int> pr, br;
int main() {
  cin >> s;
  n = (int)s.size();
  for (int i = 0; i < n; i++) {
    pAr[i] = -1;
    if (s[i] == '[') br.push_back(i);
    if (s[i] == '(') pr.push_back(i);
    if (s[i] == ']') {
      if (br.empty())
        pAr[i] = -1;
      else
        pAr[i] = br.back(), pAr[br.back()] = i, br.pop_back();
    }
    if (s[i] == ')') {
      if (pr.empty())
        pAr[i] = -1;
      else
        pAr[i] = pr.back(), pAr[pr.back()] = i, pr.pop_back();
    }
  }
  if (s[n - 1] == '(' || s[n - 1] == '[') dp[n - 1] = -1;
  int Max = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == '(') {
      if (dp[i + 1] == -1 || pAr[i] == -1 || (i + dp2[i + 1] + 1 != pAr[i]))
        dp[i] = -1, dp2[i] = -1;
      else {
        dp[i] = dp[i + 1], dp2[i] = dp2[i + 1] + 2;
        if (pAr[i] + 1 < n && dp[pAr[i] + 1] > 0)
          dp[i] += dp[pAr[i] + 1], dp2[i] += dp2[pAr[i] + 1];
      }
    }
    if (s[i] == '[') {
      if (dp[i + 1] == -1 || pAr[i] == -1 || (i + dp2[i + 1] + 1 != pAr[i]))
        dp[i] = -1, dp2[i] = -1;
      else {
        dp[i] = dp[i + 1] + 2, dp2[i] += dp2[i + 1] + 2;
        if (pAr[i] + 1 < n && dp[pAr[i] + 1] > 0)
          dp[i] += dp[pAr[i] + 1], dp2[i] += dp2[pAr[i] + 1];
      }
    }
    Max = max(Max, dp[i]);
  }
  cout << Max / 2 << endl;
  for (int i = 0; i < n; i++) {
    if (dp[i] == Max) {
      for (int j = i; j < i + dp2[i]; j++) cout << s[j];
      cout << endl;
      return 0;
    }
  }
  return 0;
}
