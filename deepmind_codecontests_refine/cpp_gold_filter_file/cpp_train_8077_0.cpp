#include <bits/stdc++.h>
using namespace std;
int arr[10005];
int main() {
  int n = ({
    int a;
    scanf("%d", &a);
    a;
  }),
      m = ({
        int a;
        scanf("%d", &a);
        a;
      }),
      c = 1;
  while (n > -1 && m > -1) {
    n -= c, m -= c + 1;
    c += 2;
  }
  if (n < 0) {
    puts("Vladik");
  } else {
    puts("Valera");
  }
}
