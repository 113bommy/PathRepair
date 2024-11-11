#include <bits/stdc++.h>
using namespace std;
string S;
vector<vector<vector<int> > > cc;
int dp(int idx, int d, int s) {
  int &ret = cc[idx][d][s];
  if (ret != -1) return ret;
  if (idx == S.size() / 2) {
    if (S.size() % 2) {
      int x = S[idx] - '0';
      if ((10 * d + x - s) < 0 || (x - s) % 2)
        return 0;
      else
        return 1;
    } else
      return d == s;
  }
  ret = 0;
  for (int i = idx == 0; i <= 18; i++) {
    int x = S[idx] - '0';
    if ((s + i) % 10 != x) continue;
    int y = S[S.size() - 1 - idx] - '0';
    if (10 * d + y - i != 0 && 10 * d + y - i != 1) continue;
    ret |= dp(idx + 1, 10 * d + y - i, i + s >= 10);
  }
  return ret;
}
vector<int> A;
void dfs(int idx, int d, int s) {
  if (idx == S.size() / 2) {
    if (S.size() % 2) {
      int x = S[idx] - '0';
      A[idx] = (10 * d + x - s) / 2;
      return;
    } else
      return;
  }
  for (int i = idx == 0; i <= 18; i++) {
    int x = S[idx] - '0';
    if ((s + i) % 10 != x) continue;
    int y = S[S.size() - 1 - idx] - '0';
    if (10 * d + y - i != 0 && 10 * d + y - i != 1) continue;
    if (dp(idx + 1, 10 * d + y - i, i + s >= 10)) {
      A[idx] = i / 2;
      A[S.size() - 1 - idx] = i - i / 2;
      dfs(idx + 1, 10 * d + y - i, i >= 10);
      return;
    }
  }
}
int main() {
  cin >> S;
  reverse(S.begin(), S.end());
  cc = vector<vector<vector<int> > >(
      S.size(), vector<vector<int> >(2, vector<int>(2, -1)));
  if (dp(0, 0, 0)) {
    A.resize(S.size());
    dfs(0, 0, 0);
    reverse(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
      printf("%d", A[i]);
    }
    return 0;
  }
  if (S[S.size() - 1] != '1') {
    printf("0");
    return 0;
  }
  S.erase(S.end() - 1);
  cc = vector<vector<vector<int> > >(
      S.size() + 1, vector<vector<int> >(2, vector<int>(2, -1)));
  if (dp(0, 1, 0)) {
    A.resize(S.size());
    dfs(0, 1, 0);
    reverse(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
      printf("%d", A[i]);
    }
    return 0;
  }
  printf("0");
}
