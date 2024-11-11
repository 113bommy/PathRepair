#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int Mx = 1000001;
  int div[1000001];
  int prime[1000001];
  int i;
  int j, k, count;
  for (i = 1; i <= Mx; i++) {
    div[i] = 1;
    prime[i] = 1;
  }
  for (i = 2; i < Mx; i++) {
    if (prime[i]) {
      div[i] = 2;
      for (j = i * 2; j < Mx; j += i) {
        k = j;
        count = 0;
        while (k % i == 0) {
          k /= i;
          count++;
        }
        div[j] *= (count + 1);
        prime[j] = 0;
      }
    }
  }
  int sum = 0;
  for (i = 1; i <= a; i++) {
    for (j = 1; j <= b; j++) {
      for (k = 1; k <= c; k++) {
        count = i * j * k;
        sum += div[count];
        sum = sum % 1073741824;
      }
    }
  }
  cout << sum << endl;
  return 0;
}
