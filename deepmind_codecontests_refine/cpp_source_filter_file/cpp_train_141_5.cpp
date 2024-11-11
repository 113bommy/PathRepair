#include <bits/stdc++.h>
const int MAXN = 100002;
using namespace std;
int stringtoint(string s) {
  if (s.empty()) {
    return -1;
  }
  istringstream iss(s);
  int i;
  iss >> i;
  return i;
}
int main() {
  int n, x;
  cin >> n >> x;
  x--;
  vector<int> prev(n);
  vector<int> next(n);
  for (int i = 0; i < n; i++) next[i] = -1;
  vector<int> st;
  vector<int> siz;
  int smst;
  for (int i = 0; i < n; i++) {
    cin >> prev[i];
    prev[i]--;
    if (prev[i] >= 0)
      next[prev[i]] = i;
    else {
      st.push_back(i);
      siz.push_back(0);
    }
  }
  for (int i = 0; i < st.size(); i++) {
    int temp = st[i];
    if (temp == x) smst = i;
    siz[i]++;
    while (next[temp] != -1) {
      temp = next[temp];
      siz[i]++;
      if (temp == x) smst = i;
    }
  }
  int smsiz = 1;
  for (int temp = st[smst]; temp != x; temp = next[temp]) {
    smsiz++;
  }
  vector<int> qs;
  for (int i = 0; i < st.size(); i++) {
    if (i != smst) qs.push_back(siz[i]);
  }
  sort(qs.begin(), qs.end());
  vector<vector<bool> > dp(102);
  for (int i = 0; i < dp.size(); i++) dp[i].resize(102);
  dp[0][0] = 1;
  for (int i = 1; i <= qs.size(); i++) {
    for (int j = 0; j < dp[i].size(); j++) {
      dp[i][j] =
          (dp[i - 1][j]) || (j - qs[i - 1] >= 0 && (dp[i - 1][j - qs[i - 1]]));
    }
  }
  for (int i = 0; i < dp[qs.size()].size(); i++) {
    if (dp[qs.size()][i]) cout << i + smsiz << endl;
  }
}
