#include <bits/stdc++.h>
int main() {
  int n, na[105];
  scanf("%d", &n);
  int temp, index_no = 0, index_no2 = 0;
  int odd_N = 0, even_N = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &na[i]);
    temp = (na[i] % 2);
    if (temp == 0) {
      even_N++;
      index_no = i;
    } else {
      odd_N++;
      index_no2 = i;
    }
  }
  if (even_N < odd_N) {
    printf("%d\n", index_no);
  } else
    printf("%d\n", index_no2);
}
