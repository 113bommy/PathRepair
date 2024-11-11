#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int sum = n * 1ll * (n + 1) / 2;
  if (sum % 2 == 0)
    printf("%d", 0);
  else
    printf("%d", 1);
}
