#include <bits/stdc++.h>
using namespace std;
int sum[200010];
int main() {
  int n, s, a;
  cin >> n >> s;
  int err = 0;
  for (int c = 1; c <= n; c++) {
    cin >> a;
    if (c == s) {
      if (a != 0) {
        err = 1;
        a = 0;
      }
    }
    sum[a]++;
  }
  int nonz = sum[0] - 1;
  int sol = n, hole = 0, fir = sum[0];
  for (int c = 1; c <= n - 1; c++) {
    if (sum[c] == 0) hole++;
    fir += sum[c];
    sol = min(sol, max(n - fir, hole - nonz));
  }
  printf("%d", sol + err + nonz);
}
