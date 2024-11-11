#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 1)
    printf("black\n");
  else {
    printf("white\n");
    printf("%d %d\n", 1, n / 2 + 1);
  }
  return 0;
}
