#include <bits/stdc++.h>
using namespace std;
int n;
char s[100100];
int main() {
  scanf("%d%s", &n, s);
  for (int i = 0, t = 1; i < n; i += t++) {
    printf("%c", s[i]);
  }
}
