#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a < 1) {
    return 0;
  }
  if (b < a) {
    return 0;
  }
  if (b > 1000000) {
    return 0;
  }
  int v[10];
  v[0] = 6;
  v[1] = 2;
  v[2] = 5;
  v[3] = 5;
  v[4] = 4;
  v[5] = 5;
  v[6] = 6;
  v[7] = 3;
  v[8] = 7;
  v[9] = 8;
  int soma = 0;
  for (int i = a; i <= b; ++i) {
    int n = i;
    while (n > 0) {
      soma += v[n % 10];
      n = n / 10;
    }
  }
  cout << soma << endl;
}
