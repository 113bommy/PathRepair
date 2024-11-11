#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int n;
int main() {
  int a[4];
  for (int i = 1; i <= 3; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 4);
  if (a[1] >= 4) {
    puts("NO");
    exit(0);
  }
  if (a[1] == 1) {
    puts("YES");
    exit(0);
  }
  if (a[1] == 2 && a[2] == 2) {
    puts("YES");
    exit(0);
  }
  if (a[1] == 2 && a[2] == a[3] && a[3] == 4) {
    puts("YES");
    exit(0);
  }
  if (a[1] == 3 && a[2] == 3 && a[3] == 3) {
    puts("YES");
    exit(0);
  }
  puts("NO");
  exit(0);
}
