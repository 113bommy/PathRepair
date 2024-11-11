#include <bits/stdc++.h>
using namespace std;
vector<int> x(11), z(11);
void kek(long long int a) {
  long long int b = a;
  for (int i = 0; i < 11; i++) {
    x[i] = b % 2;
    b = b / 2;
  }
}
long long int poww(int q, int w) {
  long long k = 1;
  for (int i = 0; i < w; i++) {
    k *= q;
  }
  return (k);
}
int main() {
  long long int n;
  cin >> n;
  int y;
  int mi = 10000;
  int p = n;
  int a = 0;
  while (p > 0) {
    a++;
    p = p / 10;
  }
  for (int i = 0; i < a; i++) {
    z[i] = n / (poww(10, i)) % 10;
  }
  for (int i = 1; i < pow(2, a); i++) {
    kek(i);
    int l = 0;
    y = 0;
    for (int j = 0; j < a; j++) {
      y = y + x[j] * z[j] * pow(10, l);
      if (x[j] == 1) l++;
    }
    if (y >= pow(10, l - 1) && a - l < mi && sqrt(y) == ceil(sqrt(y)))
      mi = a - l;
  }
  if (mi > 12)
    cout << -1;
  else
    cout << mi;
  cin >> mi;
  return (0);
}
