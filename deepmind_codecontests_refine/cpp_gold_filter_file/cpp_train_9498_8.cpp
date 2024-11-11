#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  int len = 0;
  char s[105];
  while (scanf("%c", &c) != EOF) {
    s[len++] = c;
  }
  int before = 0;
  for (int j = 0; j < len - 1; j++) {
    int c = s[j];
    int a = 7;
    int sum = 0;
    while (c > 0) {
      sum += ((c & 1) << a);
      c = c / 2;
      a--;
    }
    int k = (before - sum) % 256;
    before = sum;
    if (k < 0)
      cout << 256 + k << endl;
    else
      cout << k << endl;
  }
}
