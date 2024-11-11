#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int num[1111];
  int s[1111];
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &num[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  int maxi = 0;
  int temp = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    maxi = max(maxi, s[i]);
    temp += s[i];
    if (temp >= num[i]) {
      temp -= num[i];
      ans += num[i];
      continue;
    } else {
      int diff = num[i] - temp;
      int tambah = (int)ceil((double)diff / (double)maxi);
      temp += maxi * tambah;
      ans += k * tambah;
      temp -= num[i];
      ans += num[i];
    }
  }
  printf("%d\n", ans);
  return 0;
}
