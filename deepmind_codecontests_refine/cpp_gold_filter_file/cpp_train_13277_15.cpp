#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
  if (a < b)
    return true;
  else
    return false;
}
int main(void) {
  int n, arr[100000 + 20];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr + 1, arr + n + 1, cmp);
  int temp = 0;
  for (int i = 1; i <= n; i++) {
    if (temp == arr[i]) continue;
    if (arr[i] > temp) {
      temp++;
      arr[i] = temp;
    }
  }
  printf("%d\n", temp + 1);
  return 0;
}
