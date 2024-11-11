#include <bits/stdc++.h>
using namespace std;
string s;
int b[10];
int main() {
  int t, n, i, j;
  scanf("%d", &n);
  cin >> s;
  int c = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == '8') {
      c++;
    }
  }
  if (c == 0) {
    printf("0\n");
  } else {
    printf("%d\n", min(c, n / 11));
  }
  return 0;
}
