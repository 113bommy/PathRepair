#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    printf("-1");
    return 0;
  }
  if (n == 2 || n == 3) {
    printf("2 2");
    return 0;
  }
  if (n % 2) n--;
  printf("2 %d", n);
}
