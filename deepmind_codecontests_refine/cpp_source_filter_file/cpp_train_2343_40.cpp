#include <bits/stdc++.h>
using namespace std;
long long n, arr[1000005], a, cnt;
int main() {
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a);
    arr[a]++;
  }
  for (int i = 0; i <= 1000000; i++) {
    arr[i + 1] = arr[i + 1] + (arr[i] - arr[i] % 2) / 2;
    cnt = cnt + arr[i] % 2;
  }
  cout << cnt;
  return 0;
}
