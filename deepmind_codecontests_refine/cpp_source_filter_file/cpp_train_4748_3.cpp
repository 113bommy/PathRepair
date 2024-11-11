#include <bits/stdc++.h>
int main() {
  int n, a, b, c(0), outOfService(0), current;
  std ::cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    std ::cin >> current;
    if (current == 1) {
      if (a)
        a--;
      else if (b) {
        b--;
        c++;
      } else if (c)
        c--;
      else
        outOfService++;
    } else {
      if (b)
        b--;
      else
        outOfService++;
    }
  }
  std ::cout << outOfService << std ::endl;
}
