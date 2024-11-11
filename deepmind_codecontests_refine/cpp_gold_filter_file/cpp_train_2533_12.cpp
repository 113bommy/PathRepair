#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int c[100000] = {n}, count = 0;
  while (c[count] > 1) {
    int f[100000], num = 0;
    for (int i = 1; i <= sqrt(n); i++) {
      if (n % i == 0) {
        num++;
        f[num] = i;
      }
    }
    int temp = 0;
    for (int i = num; i >= 1; i--) {
      if (f[i] * f[i] == n) continue;
      temp++;
      f[num + temp] = n / f[i];
    }
    for (int i = 2; i <= num + temp; i++) {
      if (n / f[i] < c[count]) {
        count++;
        c[count] = n / f[i];
        n = c[count];
        break;
      }
    }
  }
  int total = 0;
  for (int i = 0; i <= count; i++) total += c[i];
  cout << total;
}
