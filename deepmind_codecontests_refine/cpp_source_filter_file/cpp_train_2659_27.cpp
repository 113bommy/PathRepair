#include <bits/stdc++.h>
int main() {
  int a, b, count1 = 0, count2 = 0, i;
  int arr[a];
  scanf("%d %d", &a, &b);
  for (i = 0; i < a; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] < b) {
      count1++;
    } else
      count2 = count2 + 2;
  }
  printf("%d", count1 + count2);
}
