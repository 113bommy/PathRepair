#include <bits/stdc++.h>
using namespace std;
long long n, neg, c, pos, res, posi;
long long arr[105], x, a;
int main() {
  c = 1;
  scanf("%I64d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d%I64d", &x, &a);
    if (x < 0) {
      neg++;
      arr[c] = (x * 1000000) - a;
      c++;
    } else {
      arr[c] = x * 1000000 + a;
      c++;
      pos++;
    }
  }
  sort(arr + 1, arr + n + 1);
  if (neg > pos) {
    posi = neg + 1;
    while (neg != 0 && pos != -1) {
      res += (arr[neg--] % 1000000) * -1;
      res += arr[posi++] % 1000000;
      pos--;
    }
  } else {
    posi = neg + 1;
    while (neg != -1 && pos != 0) {
      res += arr[posi++] % 1000000;
      res += (arr[neg--] % 1000000) * -1;
      pos--;
    }
  }
  printf("%I64d\n", res);
}
