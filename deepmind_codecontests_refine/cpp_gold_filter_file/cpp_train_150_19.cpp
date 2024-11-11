#include <bits/stdc++.h>
using namespace std;
static const int N = 100;
char s[N + 1];
bool funk(int pos, int val) {
  for (int i = 0; i < 5; i++) {
    if (s[pos] == '.') return 0;
    pos += val;
  }
  return 1;
}
int main() {
  int n;
  scanf("%i", &n);
  scanf("%s", &s);
  for (int i = 1; 4 * i <= n; i++) {
    for (int j = 0; j + 4 * i < n; j++) {
      if (funk(j, i)) {
        printf("yes\n");
        return 0;
      }
    }
  }
  printf("no\n");
  return 0;
}
