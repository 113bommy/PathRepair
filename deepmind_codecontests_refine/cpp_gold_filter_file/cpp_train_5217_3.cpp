#include <bits/stdc++.h>
using namespace ::std;
int main() {
  int n;
  scanf("%d", &n);
  if (n <= 10)
    puts("0");
  else if (n <= 21 && n > 10) {
    if (n != 20)
      puts("4");
    else
      puts("15");
  } else
    puts("0");
  return 0;
}
