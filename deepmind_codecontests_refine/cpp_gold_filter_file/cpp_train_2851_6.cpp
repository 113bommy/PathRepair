#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20, K = 20;
const int mod = 998244353;
const int MX = 2760131;
int o = 0, t = 0;
int arr[2][N];
bool ck(int one, int two, int mx) {
  if (one > o || two > t) return 0;
  int sum = 0;
  for (int i = 0; i < o - one; i++) {
    sum += arr[0][i];
  }
  for (int i = 0; i < t - two; i++) {
    sum += arr[1][i];
  }
  if (sum > mx)
    return 0;
  else
    return 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == 1)
      arr[0][o++] = y;
    else
      arr[1][t++] = y;
  }
  sort(arr[0], arr[0] + o);
  sort(arr[1], arr[1] + t);
  for (int i = 1; i <= n * 2; i++) {
    for (int j = 0; j <= o; j++) {
      if ((i - j) >= 0 && (i - j) % 2 == 0) {
        if (ck(j, (i - j) / 2, i)) {
          return cout << i, 0;
        }
      }
    }
  }
}
