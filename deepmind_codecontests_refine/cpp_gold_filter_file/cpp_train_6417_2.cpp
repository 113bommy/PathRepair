#include <bits/stdc++.h>
using namespace std;
int a[10001];
void find() {
  int i, j, k, p, m, n, q, w, z, t = 0;
  for (i = 0; i < 10; i++)
    for (j = 0; j < 10; j++)
      for (k = 0; k < 10; k++)
        for (p = 0; p < 10; p++)
          for (m = 0; m < 10; m++)
            for (n = 0; n < 10; n++)
              for (q = 0; q < 10; q++)
                for (w = 0; w < 10; w++)
                  if (i + j + k + p + m + n + q + w == 10) {
                    a[t++] = i * 10000000 + j * 1000000 + k * 100000 +
                             p * 10000 + m * 1000 + n * 100 + q * 10 + w;
                    if (t == 10000) return;
                  }
}
int main() {
  find();
  sort(a, a + 10001);
  int n;
  cin >> n;
  cout << a[n];
}
