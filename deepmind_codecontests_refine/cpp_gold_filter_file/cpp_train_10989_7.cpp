#include <bits/stdc++.h>
using namespace std;
long long res[100];
int main() {
  long long n;
  scanf("%lld", &n);
  res[0] = 1;
  res[1] = 2;
  for (int i = 2; i < 100; ++i) {
    res[i] = res[i - 1] + res[i - 2];
    if (res[i] > n) {
      cout << i - 1 << "\n";
      return 0;
    }
  }
}
