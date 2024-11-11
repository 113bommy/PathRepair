#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  long long int inp;
  long long int grundy = 0;
  for (int i = 0; i < n; i++) {
    cin >> inp;
    if (inp % 2 == 0) grundy = grundy ^ (1);
    if (grundy == 0)
      printf("2\n");
    else
      printf("1\n");
  }
  return 0;
}
