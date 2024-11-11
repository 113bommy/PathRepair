#include <bits/stdc++.h>
using namespace std;
long long pow(int a, int n) {
  long long m = 1;
  while (n--) {
    m = (m * a) % 1000000007;
  }
  return m;
}
bool cmp(int a, int b) { return a > b; }
int main() {
  int a[4] = {0};
  char s;
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("%c", &s);
    switch (s) {
      case 'A':
        a[0]++;
        break;
      case 'T':
        a[1]++;
        break;
      case 'G':
        a[2]++;
        break;
      case 'C':
        a[3]++;
        break;
    }
  }
  sort(a, a + 4, cmp);
  if (a[0] > a[1])
    printf("1\n");
  else if (a[1] > a[2]) {
    printf("%I64d\n", pow(2, n));
  } else if (a[2] > a[3]) {
    printf("%I64d\n", pow(3, n));
  } else
    printf("I64d\n", pow(4, n));
  return 0;
}
