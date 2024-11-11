#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int x;
  scanf("%d", &x);
  vector<int> divisors;
  int limit = (int)sqrt(x);
  for (int i = 1; i <= limit; ++i)
    if (x % i == 0) {
      divisors.push_back(i);
      int other = x / i;
      if (other != 1) divisors.push_back(other);
    }
  vector<bool> digits(10);
  while (x > 0) {
    digits[x % 10] = true;
    x /= 10;
  }
  int cnt = 0;
  for (int i = 0; i < divisors.size(); ++i) {
    int n = divisors[i];
    while (n > 0) {
      if (digits[n % 10]) {
        cnt++;
        break;
      }
      n /= 10;
    }
  }
  printf("%d\n", cnt);
  return EXIT_SUCCESS;
}
