#include <bits/stdc++.h>
using namespace std;
long long n, m, c, d, e, i = 1, j = 1, k, l, ab[1000001], ac[1000001], s = 0;
int main() {
  cin >> n >> m >> l;
  while (n * i <= l) {
    ab[i] = i * n;
    i++;
  }
  k = i;
  while (m * j <= l) {
    ac[j] = j * m;
    j++;
  }
  l = j;
  for (i = 1; i <= k; i++) {
    for (j = 1; j <= l; j++) {
      if (ab[i] == ac[j]) s++;
    }
  }
  cout << s;
}
