#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  char *str = new char[n + 1];
  scanf("%s", str);
  int a = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] == 'A') {
      ++a;
    } else {
      ++b;
    }
  }
  if (a < b) {
    printf("Anton\n");
  } else if (b < a) {
    printf("Danik\n");
  } else {
    printf("Friendship\n");
  }
  return 0;
}
