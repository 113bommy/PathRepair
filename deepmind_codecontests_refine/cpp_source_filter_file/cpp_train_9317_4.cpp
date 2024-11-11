#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  for (int i = n; i > 0; i--)
    if (n % i == 0) printf("%d ", i);
  return 0;
}
