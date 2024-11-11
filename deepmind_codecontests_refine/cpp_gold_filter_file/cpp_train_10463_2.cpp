#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
const int MOD = 1000000007;
int Arr[200007], n;
int main(int argc, const char **argv) {
  while (~scanf("%d", &n)) {
    for (int i = 0; i <= (n - 1); ++i) scanf("%d", Arr + i);
    sort(Arr, Arr + n);
    int t = (n / 2);
    int mmx = (1 << 30);
    for (int i = 0; i <= (t - 1); ++i) {
      mmx = min(mmx, (Arr[i + (n / 2)] - Arr[i]));
    }
    printf("%d\n", mmx);
  }
  return 0;
}
