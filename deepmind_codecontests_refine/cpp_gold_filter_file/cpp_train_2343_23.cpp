#include <bits/stdc++.h>
using namespace std;
int arr[2000010 + 10];
int main() {
  int i, n, a, ans;
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    arr[a]++;
  }
  ans = 0;
  for (i = 0; i < 2000010; i++) {
    if (arr[i] >= 2) {
      arr[i + 1] += arr[i] / 2;
      arr[i] %= 2;
    }
    if (arr[i]) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
