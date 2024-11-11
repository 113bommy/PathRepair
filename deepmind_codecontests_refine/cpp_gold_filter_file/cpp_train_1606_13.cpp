#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int arr1[N], arr2[N];
char ans1[N], ans2[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", arr1 + i, arr2 + i);
    ans1[i] = ans2[i] = '0';
  }
  int i = 0, j = 0, k = n;
  while (k > 0) {
    if (arr1[i] < arr2[j])
      ans1[i++] = '1';
    else
      ans2[j++] = '1';
    --k;
  }
  i = 0, k = n / 2;
  while (i < k) {
    ans1[i] = ans2[i] = '1';
    ++i;
  }
  if (n & 1) {
    if (arr1[i] < arr2[i])
      ans1[i] = '1';
    else
      ans2[i] = '1';
  }
  printf("%s\n%s\n", ans1, ans2);
  return 0;
}
