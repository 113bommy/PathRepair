#include <bits/stdc++.h>
char a[100000 + 99];
using namespace std;
int main() {
  long len, sum;
  cin >> a;
  len = strlen(a);
  sum = (a[len - 2] - '0') * 10 + (a[len - 1] - '0');
  printf("%d\n", (sum % 4 == 0) ? 4 : 0);
}
