#include <bits/stdc++.h>
using namespace std;
long long int cc[778][8];
int main() {
  long long n;
  cin >> n;
  for (int i = 0; i < 778; i++) {
    cc[i][0] = 1;
    cc[i][1] = i;
  }
  for (int in = 1; in < 778; in++) {
    for (int ik = 2; ik < 6; ik++) {
      cc[in][ik] = cc[in - 1][ik - 1] + cc[in - 1][ik];
    }
  }
  cout << (n + 2 * n * (n - 1) + n * (n - 1) * (n - 2) +
           n * (n - 1) * (n - 2) * (n - 3) / 6 + cc[n][5]) *
              (n + n * (n - 1) + cc[n][3]);
}
