#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, co = 0;
  cin >> a >> b;
  for (int i = 1; i * i <= b; i++) {
    if (b % i == 0 && b / i <= a && i <= a) {
      if (i == b / i) co--;
      co += 2;
    }
  }
  printf("%d\n", co);
}
