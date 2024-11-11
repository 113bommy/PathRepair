#include <bits/stdc++.h>
using namespace std;
vector<long long int> vii[101];
long long int n, a, b, num, sum = 0, lev[101], leaflev[101], cnt = 0, k, l;
int line[201];
bool vis[101];
bool dp[201][201];
queue<int> q;
bool sol(long long int currlen, long long int currline) {
  if (dp[currline][currlen] == 0) return false;
  if (currline == k && (currlen < a || currlen > b)) {
    return false;
  }
  if (currlen == 0) return false;
  if (currline == k && currlen >= a && currlen <= b) {
    line[currline] = currlen;
    cnt = 1;
    return true;
  }
  for (long long int i = a; i <= b; i++) {
    line[currline] = i;
    if (sol(currlen - i, currline + 1)) {
      return true;
    }
  }
  dp[currline][currlen] = false;
  return false;
}
int main() {
  cin >> k >> a >> b;
  string s;
  cin >> s;
  l = s.length();
  for (int i = 0; i < 201; i++) {
    for (int j = 0; j < 201; j++) {
      dp[i][j] = -1;
    }
  }
  if (k * a > l || k * b < l) {
    cout << "No solution";
    return 0;
  } else {
    for (long long int i = a; i <= b; i++) {
      line[1] = i;
      if (sol(l - i, 2)) {
        break;
      }
    }
  }
  if (cnt == 0)
    cout << "No solution";
  else {
    long long int cur = 0;
    for (long long int i = 1; i <= k; i++) {
      for (long long int j = cur; j < line[i] + cur; j++) {
        cout << s[j];
      }
      cur += line[i];
      cout << endl;
    }
  }
  return 0;
}
