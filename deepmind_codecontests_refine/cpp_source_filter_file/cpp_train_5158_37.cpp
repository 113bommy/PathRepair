#include <bits/stdc++.h>
using namespace std;
long long a, b, s, p, sum;
int main() {
  cin >> a >> b;
  if (a > b) {
    long long aux = a;
    b = a;
    a = aux;
  }
  for (long long i = 1; i <= a; ++i) {
    sum = b + i;
    s = s + sum / 5 - i / 5;
  }
  cout << s;
  return 0;
}
