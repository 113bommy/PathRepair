#include <bits/stdc++.h>
int p[4], a, b, n, res;
using namespace std;
int main() {
  for (int i = 0; i < 4; i++) cin >> p[i];
  cin >> a >> b;
  for (int m = a; m < b; m++) {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        if (j != i)
          for (int k = 0; k < 4; k++)
            if (k != j && k != i)
              for (int l = 0; l < 4; l++)
                if (l != k && l != j && l != i &&
                    ((((m % p[i]) % p[j]) % p[k]) % p[l]) == m)
                  n++;
    if (n >= 7) res++;
    n = 0;
  }
  cout << res;
  return 0;
}
