#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, kil = 0;
  cin >> n;
  if (n < 4) {
    cout << "NO\n";
    return 0;
  }
  printf("YES\n");
  if (n % 2 == 0) {
    for (int i = n; i >= 6; i -= 2) {
      printf("%d - %d = 1\n", i, i - 1);
      kil++;
    }
    while (kil > 0) {
      printf("1 * 1 = 1\n");
      kil--;
    }
    printf("1 * 2 = 2\n");
    printf("3 * 4 = 12\n");
    printf("12 * 2 = 24\n");
  } else {
    for (int i = n; i > 6; i -= 2) {
      printf("%d - %d = 1\n", i, i - 1);
      kil++;
    }
    while (kil > 0) {
      printf("1 * 1 = 1\n");
      kil--;
    }
    printf("1 + 2 = 3\n");
    printf("5 - 2 = 3\n");
    printf("2 * 3 = 6\n");
    printf("6 * 4 = 24\n");
  }
  return 0;
}
