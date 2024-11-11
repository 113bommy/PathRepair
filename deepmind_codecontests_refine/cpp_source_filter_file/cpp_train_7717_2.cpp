#include <bits/stdc++.h>
using namespace std;
int memo[5001][5001];
int n;
int arr[5001];
int l[5001];
int r[5001];
int backtrack(int a, int b) {
  if (memo[a][b] != -1) return memo[a][b];
  if (a == 1 && b == n) return 0;
  if (a == 1) return memo[a][b] = backtrack(a, r[b + 1]) + 1;
  if (b == n) return memo[a][b] = backtrack(l[a - 1], b) + 1;
  if (arr[a - 1] == arr[b - 1])
    return memo[a][b] = backtrack(l[a - 1], r[b + 1]) + 1;
  int cur = 1e9;
  cur = min(cur, backtrack(l[a - 1], b) + 1);
  cur = min(cur, backtrack(a, r[b + 1]) + 1);
  return memo[a][b] = cur;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i <= 5000; i++)
    for (int j = 0; j <= 5000; j++) memo[i][j] = -1;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int pos = 1;
  int prev = arr[1];
  for (int i = 1; i <= n; i++) {
    if (arr[i] != prev) {
      pos = i;
      prev = arr[i];
    }
    l[i] = pos;
  }
  pos = n;
  prev = arr[n];
  for (int i = n; i >= 1; i--) {
    if (arr[i] != prev) {
      pos = i;
      prev = arr[i];
    }
    r[i] = pos;
  }
  int res = 1e9;
  for (int i = 1; i <= n; i++) {
    int a = l[i];
    int b = r[i];
    res = min(res, backtrack(a, b));
  }
  cout << res;
}
