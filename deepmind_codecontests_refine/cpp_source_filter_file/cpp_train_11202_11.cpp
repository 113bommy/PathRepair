#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; i < c.size(); ++i) {
    bool isUp = false;
    if (c[i] >= 'A' && c[i] <= 'Z') {
      isUp = true;
      c[i] = c[i] - 'A' + 'a';
    } else if (c[i] >= '0' && c[i] <= '9')
      printf("%c", c[i]);
    else {
      for (int j = 0; j < a.size(); ++j) {
        if (c[i] == a[j]) {
          if (isUp)
            printf("%c", b[j] + 'A' - 'a');
          else
            printf("%c", b[j]);
        }
      }
    }
  }
  return 0;
}
