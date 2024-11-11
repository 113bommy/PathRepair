#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int dp[N][N][N];
string s1, s2, v;
int Fail[N];
bool valid = false;
void failure_function() {
  for (int i = 1, k = 0; i < v.size(); ++i) {
    if (k > 0 && v[i] != v[k]) k = Fail[k - 1];
    if (v[i] == v[k]) k++;
    Fail[i] = k;
  }
}
int solve(int i, int j, int cnt) {
  if (cnt == v.size()) return -1e9;
  if (i == s1.size() || j == s2.size()) return 0;
  int &ret = dp[i][j][cnt];
  if (~ret) return ret;
  ret = 0;
  ret = max(ret, max(solve(i + 1, j, cnt), solve(i, j + 1, cnt)));
  if (s1[i] == s2[j]) {
    if (s1[i] == v[cnt])
      ret = max(ret, solve(i + 1, j + 1, cnt + 1) + 1);
    else {
      while (cnt > 0 && v[cnt] != s1[i]) cnt = Fail[cnt - 1];
      ret = max(ret,
                solve(i + 1, j + 1, ((v[cnt] == s1[i]) ? cnt + 1 : cnt)) + 1);
    }
  }
  return ret;
}
void printAnswer(int i, int j, int cnt) {
  if (cnt == v.size()) return;
  if (i == s1.size() || j == s2.size()) return;
  if (solve(i + 1, j, cnt) == solve(i, j, cnt)) {
    printAnswer(i + 1, j, cnt);
    return;
  }
  if (solve(i, j + 1, cnt) == solve(i, j, cnt)) {
    printAnswer(i, j + 1, cnt);
    return;
  }
  if (s1[i] == s2[j]) {
    if (s1[i] == v[cnt]) {
      if ((solve(i + 1, j + 1, cnt + 1) + 1) == solve(i, j, cnt)) {
        cout << s1[i];
        printAnswer(i + 1, j + 1, cnt + 1);
        return;
      }
    } else {
      while (cnt > 0 && v[cnt] != s1[i]) cnt = Fail[cnt - 1];
      if ((solve(i + 1, j + 1, ((v[cnt] == s1[i]) ? cnt + 1 : cnt)) + 1) ==
          solve(i, j, cnt)) {
        cout << s1[i];
        printAnswer(i + 1, j + 1, ((v[cnt] == s1[i]) ? cnt + 1 : cnt));
        return;
      }
    }
  }
}
int main() {
  cin >> s1 >> s2 >> v;
  failure_function();
  memset(dp, -1, sizeof(dp));
  int ans = solve(0, 0, 0);
  if (ans <= 0)
    printf("0\n");
  else {
    printAnswer(0, 0, 0);
    printf("\n");
  }
}
