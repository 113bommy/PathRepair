#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n == 1) {
    printf("1 1\n");
  } else {
    long long m = n * 10 - 10;
    printf("%I64d 2\n", m);
    printf("5 2\n");
  }
}
