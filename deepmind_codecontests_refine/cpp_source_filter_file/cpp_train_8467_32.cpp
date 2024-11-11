#include <bits/stdc++.h>
using namespace std;
long n, a[100000], m, i, j, k, l, u, ki;
int main() {
  cin >> n;
  i = 1;
  a[1] = 1;
  while (a[i] <= n) {
    i++;
    a[i] = a[i - 1] + a[i - 2];
  }
  for (j = 1; j <= i - 1; j++)
    for (l = 1; l <= i - 1; l++)
      for (u = 1; u <= i - 1; u++)
        if (a[j] + a[l] + a[u] == n && ki == 0) {
          cout << a[j] << " " << a[l] << " " << a[u] << endl;
          ki = 1;
        }
  if (ki == 0) cout << "I'm too stupid to solve this problem" << endl;
}
