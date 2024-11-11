#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  for (int i = n; i >= 1; i--)
    if (n % i == 0) printf("%d ", i), n = i;
  return 0;
}
