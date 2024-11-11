#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  string s;
  cin >> s;
  int one = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'x') {
      one++;
    } else {
      zero++;
    }
  }
  if (one == zero) {
    puts("1");
    cout << s << '\n';
    return 0;
  }
  if (one > zero) {
    one -= zero;
    one >>= 1;
    printf("%d\n", one);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'x' && one) {
        s[i] = 'X';
        one--;
      }
    }
  } else {
    zero -= one;
    zero >>= 1;
    printf("%d\n", zero);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'X' && zero) {
        s[i] = 'x';
        zero--;
      }
    }
  }
  cout << s << "\n";
  return 0;
}
