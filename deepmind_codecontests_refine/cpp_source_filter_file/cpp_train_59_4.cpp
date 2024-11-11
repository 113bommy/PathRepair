#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const long long INF = 1e18;
int a[MAXN];
int num[MAXN];
int main() {
  int n;
  cin >> n;
  int L = 0, R = 0;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] >= i) {
      L++;
      num[a[i] - i]++;
    } else
      R++;
    sum += abs(a[i] - i);
  }
  long long ans = sum, k = 0;
  for (int i = 0; i < n - 1; i++) {
    L -= num[i];
    R += num[i];
    sum += -L + R - 1 - (n - a[n - i]) + (a[n - i] - 1);
    num[a[n - i] + i]++;
    L++;
    R--;
    if (sum < ans) {
      ans = sum;
      k = i + 1;
    }
  }
  cout << ans << " " << k << endl;
  return 0;
}
