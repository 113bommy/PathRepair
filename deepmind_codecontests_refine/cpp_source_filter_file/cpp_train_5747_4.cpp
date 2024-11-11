#include <bits/stdc++.h>
using namespace std;
long long p[1100000], r[1100000], cnt;
int main() {
  long long n, bac;
  cin >> n;
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  bac = n;
  long long i;
  for (i = 2; i * i <= n; i++) {
    if (bac % i == 0) {
      cnt++;
      p[cnt] = i;
      while (bac % i == 0) {
        bac /= i;
        r[cnt]++;
      }
    }
  }
  if (bac != 1) {
    cnt++;
    p[cnt] = bac;
  }
  if (cnt == 1)
    cout << p[1] << endl;
  else
    printf("2\n");
  return 0;
}
