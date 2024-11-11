#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long n;
  scanf("%I64d", &n);
  printf("%I64d", n - n / 2 - n / 3 - n / 5 - n / 7 + n / (2 * 3) +
                      n / (2 * 5) + n / (2 * 7) + n / (3 * 5) + n / (3 * 7) +
                      n / (7 * 5) - n / (3 * 2 * 5) - n / (3 * 2 * 7) -
                      n / (3 * 5 * 7) - n / (7 * 2 * 5) + n / (2 * 3 * 5 * 7));
}
