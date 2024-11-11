#include <bits/stdc++.h>
using namespace std;
string s1, s2, virus;
int dp[105][105][105];
int dir[105][105][105];
int failure[105];
void build(string pattern, int m) {
  failure[0] = 0;
  failure[1] = 0;
  int j = 0;
  for (int i = 2; i <= m; i++) {
    while (true) {
      if (pattern[i - 1] == pattern[j]) {
        failure[i] = j + 1;
        j++;
        break;
      }
      if (j == 0) {
        failure[i] = 0;
        break;
      }
      j = failure[j];
    }
  }
}
int query(int k, char ch) {
  while (failure[k]) {
    if (ch == virus[failure[k]]) return failure[k] + 1;
    k = failure[k];
  }
  return 0;
}
int solve(int i, int j, int k) {
  if (i == s1.size() || j == s2.size()) return 0;
  int &ret = dp[i][j][k];
  if (ret != -1) return ret;
  if (s1[i] == s2[j]) {
    if (virus[k] != s1[i]) {
      int kp = query(k, s1[i]);
      int a1 = 1 + solve(i + 1, j + 1, kp);
      int a2 = solve(i + 1, j + 1, k);
      if (a1 >= a2) {
        dir[i][j][k] = 3;
        return ret = a1;
      } else {
        dir[i][j][k] = 4;
        return ret = a2;
      }
    } else {
      if (k + 1 == virus.size()) {
        dir[i][j][k] = 4;
        return ret = solve(i + 1, j + 1, k);
      } else {
        int a1 = 1 + solve(i + 1, j + 1, k + 1);
        int a2 = solve(i + 1, j + 1, k);
        if (a1 >= a2) {
          dir[i][j][k] = 5;
          return ret = a1;
        } else {
          dir[i][j][k] = 4;
          return ret = a2;
        }
      }
    }
  }
  int a1 = solve(i + 1, j, k);
  int a2 = solve(i, j + 1, k);
  if (a1 >= a2) {
    dir[i][j][k] = 1;
    return ret = a1;
  } else {
    dir[i][j][k] = 2;
    return ret = a2;
  }
}
void print(int i, int j, int k) {
  if (i == s1.size() || j == s2.size())
    ;
  if (dir[i][j][k] == 1)
    print(i + 1, j, k);
  else if (dir[i][j][k] == 2)
    print(i, j + 1, k);
  else if (dir[i][j][k] == 3) {
    cout << s1[i];
    int kp = query(k, s1[i]);
    print(i + 1, j + 1, kp);
  } else if (dir[i][j][k] == 4)
    print(i + 1, j + 1, k);
  else if (dir[i][j][k] == 5) {
    cout << s1[i];
    print(i + 1, j + 1, k + 1);
  }
}
int main() {
  cin >> s1 >> s2 >> virus;
  build(virus, virus.size());
  memset(dp, -1, sizeof dp);
  if (solve(0, 0, 0))
    print(0, 0, 0);
  else
    cout << 0 << endl;
}
