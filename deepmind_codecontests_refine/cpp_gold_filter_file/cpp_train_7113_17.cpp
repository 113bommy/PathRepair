#include <bits/stdc++.h>
using namespace std;
long long int find(long long int n, long long int k) {
  long long int curk = 1, cans = 0;
  while (n >= curk) {
    cans += (n / curk);
    curk *= k;
  }
  return cans;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long int lb = 0, ub = 2000000000, mid, ans;
  while (lb <= ub) {
    mid = ((lb + ub) >> 1);
    if (find(mid, k) >= (long long int)n) {
      ans = mid;
      ub = mid - 1;
    } else
      lb = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
