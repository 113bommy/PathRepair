#include <bits/stdc++.h>
using namespace std;
long long int sum(long long int x) {
  long long int suma = 0;
  while (x) {
    suma += x % 10;
    x /= 10;
  }
  return suma;
}
long long int eleva(long long int a, long long int b) {
  long long int res = 1;
  for (int i = 1; i <= b; i++) {
    res *= a;
  }
  return res;
}
int main() {
  int a, b, c, sx, x;
  cin >> a >> b >> c;
  vector<long long int> v;
  int cont = 0;
  for (int s = 0; s <= 81; s++) {
    long long int x = b * eleva(s, a) + c;
    if (sum(x) == s && x < 1000000000) {
      v.push_back(x);
      cont++;
    }
  }
  cout << cont << endl;
  for (int i = 0; i < cont; i++) {
    cout << v[i] << " ";
  }
  return 0;
}
