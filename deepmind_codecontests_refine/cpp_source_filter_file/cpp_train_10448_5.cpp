#include <bits/stdc++.h>
using namespace std;
int kol_d(int a) {
  int s = 0;
  int b = int(sqrt(double(a)));
  for (int i = 1; i <= b; i++)
    if (a % i == 0) s += 2;
  if (long(b * b) == a) s--;
  return s;
}
int main() {
  int a, b, c;
  long long s = 0;
  scanf("%d%d%d", &a, &b, &c);
  vector<int> d(a * b * c + 1, -1);
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      for (int k = 1; k <= c; k++) {
        if (d[i * j * k] == -1) d[i * j * k] = kol_d(i * j * k);
        s = (s + d[i * j * k]) % 1073741824;
      }
  printf("%i64", s % 1073741824);
  return 0;
}
