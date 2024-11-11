#include <bits/stdc++.h>
using namespace std;
char A[1111111];
int arr[1111111];
int n, t;
int main() {
  scanf("%d%d", &n, &t);
  scanf("%s", A);
  n = strlen(A);
  int px = -1;
  for (int i = 0; i < n; ++i)
    if (A[i] == '.') {
      px = i;
      break;
    }
  for (int i = 0; i < n; ++i) arr[i] = A[i] - '0';
  int py = -1;
  for (int i = px + 1; i < n; ++i)
    if (A[i] >= '5') {
      py = i;
      break;
    }
  if (py == -1) {
    puts(A);
    return 0;
  }
  --t;
  arr[py] = 0;
  int carry = 1;
  for (int i = py - 1; i > px; --i) {
    arr[i] += carry;
    carry = arr[i] == 10;
    arr[i] -= carry * 10;
    if (arr[i] >= 5 && t >= 1) {
      --t;
      arr[i] = 0;
      carry = 1;
    }
  }
  while (arr[py - 1] == 0) --py;
  bool no_frac = carry;
  for (int i = px - 1; i >= 0; --i) {
    arr[i] += carry;
    carry = arr[i] == 10;
    arr[i] -= carry * 10;
  }
  if (carry) putchar('1');
  for (int i = 0; i < px; ++i) putchar('0' + arr[i]);
  if (!no_frac) putchar('.');
  for (int i = px + 1; i < py; ++i) putchar('0' + arr[i]);
  puts("");
  return 0;
}
