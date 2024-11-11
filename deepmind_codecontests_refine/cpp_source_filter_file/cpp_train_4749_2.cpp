#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAX = 1000005;
const double PI = acos(-1.0);
int SetBit(int n, int X) { return n | (1 << X); }
int ClearBit(int n, int X) { return n & ~(1 << X); }
int ToggleBit(int n, int X) { return n ^ (1 << X); }
bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }
int arr[100005];
int main(void) {
  int n, i, j, k;
  long long ans;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    ans = n;
    for (i = 0; i < n - 1; i++) {
      if (arr[i] == arr[i + 1]) {
        k = 1;
        for (j = i + 1; j < n; j++) {
          if (j == n - 1 && arr[i] == arr[j]) {
            ++k;
            i = j - 1;
            ans += (k * (k - 1)) / 2;
          } else if (arr[i] == arr[j])
            ++k;
          else {
            i = j - 1;
            ans += (k * (k - 1)) / 2;
            break;
          }
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
