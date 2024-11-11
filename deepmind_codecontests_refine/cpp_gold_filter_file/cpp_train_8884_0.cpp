#include <bits/stdc++.h>
using namespace std;
int n, match[1000010];
char s[1000010];
const int mm[3][3][3] = {{1, 2, 4, 2, 2, 2, 4, 2, 6},
                         {1, 1, 1, 1, 2, 4, 1, 4, 5},
                         {1, 2, 4, 2, 1, 4, 4, 4, 3}};
int solve(int L, int R) {
  if (s[L] == '(' && match[L] == R) return solve(L + 1, R - 1);
  int ret = 0;
  if (L == R) {
    if (s[L] == '0')
      ret = 1;
    else if (s[L] == '1')
      ret = 2;
    else
      ret = 4;
    return ret;
  }
  int l1 = L, r1, l2, r2 = R, mid;
  if (s[L] != '(')
    r1 = L, l2 = L + 2;
  else
    r1 = match[L], l2 = r1 + 2;
  if (s[r1 + 1] == '|')
    mid = 0;
  else if (s[r1 + 1] == '&')
    mid = 1;
  else
    mid = 2;
  int msk1 = solve(l1, r1), msk2 = solve(l2, r2);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if ((msk1 & (1 << i)) && (msk2 & (1 << j))) ret |= mm[mid][i][j];
  return ret;
}
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  stack<int> L;
  for (int i = 0; s[i]; i++)
    if (s[i] == '(')
      L.push(i);
    else if (s[i] == ')') {
      match[L.top()] = i;
      L.pop();
    }
  printf(solve(0, strlen(s) - 1) & 4 ? "YES\n" : "NO\n");
  return 0;
}
