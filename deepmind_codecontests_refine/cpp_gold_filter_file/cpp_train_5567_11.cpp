#include <bits/stdc++.h>
using namespace std;
int n, m, k, d, t, tem1, tem2, tem3, tem4, y = 1, sum = 0, ans = 0;
string s, c;
map<int, int> p;
int arr[30000 + 10];
int maxi = -1;
int dp[30000 + 10][500 + 10];
int rec(int index, int st) {
  if (index > maxi) return 0;
  int der = p[st];
  if (dp[index][der] != -1) return dp[index][der];
  int e = -1e9, r = -1e9, w = -1e9;
  if (st != 1) e = arr[index] + rec(index + st - 1, st - 1);
  r = arr[index] + rec(index + st, st);
  w = arr[index] + rec(index + st + 1, st + 1);
  return dp[index][der] = max(r, max(e, w));
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> tem1;
    maxi = max(maxi, tem1);
    arr[tem1]++;
  }
  int r2m = 1;
  for (int i = max(1, d - 250); i <= d; i++) {
    p[i] = r2m++;
  }
  for (int i = d + 1; i < d + 250; i++) {
    p[i] = r2m++;
  }
  cout << rec(d, d);
  return 0;
}
