#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int drow[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dcol[] = {1, 0, -1, -1, -1, 0, 1, 1};
int main() {
  int n, k;
  int f[100010];
  for (int i = 0; i < 100001; i++) f[i] = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    f[i % k] += x;
  }
  int ans = INT_MAX;
  int pos = 0;
  for (int i = k - 1; i >= 0; i--) {
    if (ans > f[i]) {
      ans = f[i];
      pos = i;
    }
  }
  cout << pos + 1 << '\n';
  return 0;
}
