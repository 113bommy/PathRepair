#include <bits/stdc++.h>
const long long int LL_INF = 0x3f3f3f3f3f3f;
const long long int MOD = 1073741824;
using namespace std;
int T;
int n = 1000, m, k;
int inp;
int arr[1005][1005];
set<int> st;
string str;
void gen() {}
void solve() {
  scanf("%d", &inp);
  for (int i = 0; i < inp; ++i) {
    scanf("%d", &m);
    scanf("%d", &k);
    arr[m][k] = 1;
  }
  int ans = 0;
  for (int i = 2; i <= n; ++i) {
    int x = i, j = 1, cnt = 0;
    while (x > 0) {
      cnt += arr[j][x];
      j++;
      x--;
    }
    ans += (cnt * (cnt - 1)) / 2;
  }
  for (int i = 2; i < n; ++i) {
    int x = i, j = n, cnt = 0;
    while (x < 1001) {
      cnt += arr[x][j];
      j--;
      x++;
    }
    ans += (cnt * (cnt - 1)) / 2;
  }
  for (int i = 1; i < n; ++i) {
    int x = i, j = 1, cnt = 0;
    while (x < n + 1) {
      cnt += arr[j][x];
      j++;
      x++;
    }
    ans += (cnt * (cnt - 1)) / 2;
  }
  for (int i = 2; i < n; ++i) {
    int x = i, j = 1, cnt = 0;
    while (x < 1001 && j < 1001) {
      cnt += arr[x][j];
      j++;
      x++;
    }
    ans += (cnt * (cnt - 1)) / 2;
  }
  printf("%d", ans);
}
int main() {
  memset(arr, 0, sizeof arr);
  T = 1;
  for (int i = 0; i < T; ++i) solve();
  printf("\n");
  return 0;
}
