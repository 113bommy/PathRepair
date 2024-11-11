#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  scanf("%I64d", &n);
  if (n % 4 == 0)
    printf("%d", 4);
  else
    printf("%d", 0);
}
