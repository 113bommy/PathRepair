#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int B[20];
bool vis[20];
int cnt = 0, t = 0, st = 0, x = 0, y = 0, ans = 0;
int A[1 << 20 + 1];
int solve(string s) {
  for (int i = 0; i < n; i++) {
    int j = i;
    y = 0;
    while (j < n) {
      x = s[j] - 'a';
      if ((y >> x) & 1) {
        break;
      }
      y |= (1 << x);
      A[y] = j - i + 1;
      j++;
    }
  }
  int N = 1 << 20;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 20; j++) {
      if ((i >> j) & 1) A[i] = max(A[i], A[i ^ (1 << j)]);
    }
  }
  for (int i = 0; i <= N; i++) {
    ans = max(ans, A[i] + A[(N - 1) ^ i]);
  }
  return ans;
}
int main() {
  cin >> s;
  n = s.length();
  cout << solve(s);
}
