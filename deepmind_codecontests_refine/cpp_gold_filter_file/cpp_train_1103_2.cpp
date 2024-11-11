#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, sum = 0, ans = 0;
  char n[1000000];
  cin >> k >> n;
  int l = strlen(n);
  sort(n, n + l);
  for (int i = 0; i < l; i++) {
    sum += n[i] - '0';
  }
  if (sum >= k) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < l; i++) {
    if ((sum - (n[i] - '0') + 9) >= k && n[i] != '9') {
      ans++;
      break;
    } else if (n[i] != '9') {
      sum = sum - (n[i] - '0') + 9;
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
