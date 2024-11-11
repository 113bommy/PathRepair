#include <bits/stdc++.h>
using namespace std;
int n, k, sol[300];
int main() {
  cin >> n >> k;
  for (int i = 0; i <= 255; i++) sol[i] = -1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (sol[x] != -1)
      cout << sol[x] << ' ';
    else {
      int x1 = x, nr = max(x - k + 1, 0);
      while (x1 >= nr && sol[x1] == -1) x1--;
      x1++;
      if (x1 == nr)
        for (int j = x1; j <= x; j++) sol[j] = x1;
      else {
        int x2 = x1 - 1;
        while (x2 >= 0 && sol[x2] == sol[x1 - 1]) x2--;
        x2++;
        int l1 = x - x1 + 1, l2 = x1 - x2 + 1;
        if (l1 + l2 <= k)
          for (int j = x1; j <= x; j++) sol[j] = x2;
        else
          for (int j = x1; j <= x; j++) sol[j] = x1;
      }
      cout << sol[x] << ' ';
    }
  }
  cout << '\n';
  return 0;
}
