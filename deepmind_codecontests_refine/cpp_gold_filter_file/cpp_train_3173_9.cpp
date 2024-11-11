#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int a[101];
  cin >> n >> k;
  int a_max = 0;
  int a_min = 101;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > a_max) a_max = a[i];
    if (a[i] < a_min) a_min = a[i];
  }
  if (a_max - a_min > k) {
    puts("NO");
  } else {
    puts("YES");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < a_min; j++) {
        if (j) printf(" ");
        printf("1");
      }
      for (int j = a_min; j < a[i]; j++) {
        printf(" %d", j - a_min + 1);
      }
      puts("");
    }
  }
  return 0;
}
