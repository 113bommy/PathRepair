#include <bits/stdc++.h>
using namespace std;
string str, str2;
int DP[2005][2005];
int LCCS() {
  int i, j, maxi = 0;
  for (i = 1; i <= str.size(); i++)
    for (j = 1; j <= str2.size(); j++) {
      DP[i][j] = (str[i - 1] == str2[j - 1]) ? DP[i - 1][j - 1] + 1 : 0;
      maxi = max(maxi, DP[i][j]);
    }
  return maxi;
}
void solve() {
  cin >> str >> str2;
  cout << str2.size() - LCCS() << endl;
}
int main() {
  solve();
  return 0;
}
