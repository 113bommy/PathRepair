#include <bits/stdc++.h>
using namespace std;
int totalday, number;
vector<int> g;
int day[100];
int dp[10010][110];
int flag[10010][110];
int myf(int remday, int i) {
  if (remday == 0) return 0;
  if (i == number) return 0;
  if (dp[remday][i] != -1) return dp[remday][i];
  int plusi = 0;
  if (remday >= day[i]) plusi = 1 + myf(remday - day[i], i + 1);
  int nochange = myf(remday, i + 1);
  if (plusi >= nochange) {
    flag[remday][i] = 1;
  } else
    flag[remday][i] = 0;
  return dp[remday][i] = max(plusi, nochange);
}
void findpath2(int o, int rem, int j, vector<int> &v) {}
void findpath1(int rem, int j, vector<int> &v) {
  if (flag[rem][j] == 0) {
    findpath1(rem, j + 1, v);
  } else if (flag[rem][j] == 1) {
    v.push_back(j);
    findpath1(rem - day[j], j + 1, v);
  }
}
int main() {
  cin >> number >> totalday;
  for (int i = 0; i < number; i++) cin >> day[i];
  memset(dp, -1, sizeof dp);
  memset(flag, -1, sizeof flag);
  int y = myf(totalday, 0);
  printf("%d", y);
  cout << endl;
  if (y == 0) return 0;
  findpath1(totalday, 0, g);
  for (int i = 0; i < g.size(); i++) cout << g[i] + 1 << " ";
  return 0;
}
