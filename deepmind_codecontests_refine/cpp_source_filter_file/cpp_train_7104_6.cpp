#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int t, n, k, a, b, c;
int s[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &a, &b, &c);
    if (c) {
      if (b & 1) {
        for (int i = 0; i <= c; i++) printf("1");
        for (int i = 0; i < b; i++) printf("%d", i & 1 ? 1 : 0);
        for (int i = 1; i <= a; i++) printf("0");
      } else if (b) {
        for (int i = 1; i <= c; i++) printf("1");
        for (int i = 0; i <= a; i++) printf("0");
        for (int i = 1; i < b; i++) printf("%d", i % 2);
      } else {
        for (int i = 0; i <= c; i++) printf("1");
      }
    } else {
      for (int i = 0; i <= a; i++) printf("0");
      for (int i = 1; i <= b; i++) printf("%d", i % 2);
    }
    puts("");
  }
  return 0;
}
