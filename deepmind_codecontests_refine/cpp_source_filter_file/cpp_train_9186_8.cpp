#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
unsigned long long findLcm(unsigned long long a, unsigned long long b) {
  return (a * b) / gcd(a, b);
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int findLcm(int a, int b) { return (a * b) / gcd(a, b); }
int xrr[] = {-1, 1, 0, 0};
int yrr[] = {0, 0, -1, 1};
const int size = 50;
void dfs(char arr[size][size], int visited[size][size], int x, int y, int n,
         int m) {
  visited[x][y] = 1;
  for (int k = 0; k < 4; k++) {
    int i = x + xrr[k];
    int j = y + yrr[k];
    if (i >= 0 && i <= n && j >= 0 && j <= m && visited[i][j] == 0) {
      if (arr[i][j] == 'G' || arr[i][j] == '.') {
        dfs(arr, visited, i, j, n, m);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  unsigned long long arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  unsigned long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = j; j < n; j++) {
        ans = max(ans, (arr[i] | arr[j] | arr[k]));
      }
    }
  }
  cout << ans << "\n";
  return (0);
}
