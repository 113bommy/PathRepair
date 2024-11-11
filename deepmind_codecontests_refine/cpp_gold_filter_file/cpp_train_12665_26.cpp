#include <bits/stdc++.h>
using namespace std;
int n, k;
char mp[105][105];
int sum[105][105];
bool isok(int x, int y) {
  if (1 <= x && x <= n && 1 <= y && y <= n && mp[x][y] == '.') return true;
  return false;
}
bool check(int x, int y, int k) {
  for (int i = 0; i < k; i++) {
    if (!isok(x, y + i)) return false;
  }
  return true;
}
bool check1(int x, int y, int k) {
  for (int i = 0; i < k; i++) {
    if (!isok(x + i, y)) return false;
  }
  return true;
}
void add(int x, int y, int k) {
  for (int i = 0; i < k; i++) {
    sum[x][y + i]++;
  }
}
void add1(int x, int y, int k) {
  for (int i = 0; i < k; i++) {
    sum[x + i][y]++;
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> mp[i] + 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (check(i, j, k)) {
        add(i, j, k);
      }
      if (check1(i, j, k)) {
        add1(i, j, k);
      }
    }
  }
  int ans = 0;
  int x = 1, y = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (sum[i][j] > ans) {
        ans = sum[i][j];
        x = i;
        y = j;
      }
    }
  }
  cout << x << " " << y << endl;
}
