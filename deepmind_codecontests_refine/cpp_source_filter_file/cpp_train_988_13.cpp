#include <bits/stdc++.h>
using namespace std;
int ar[1000], br[1000];
long long pow1(int a, int b) {
  long long sum = 1;
  for (int i = 0; i < a; i++) sum *= b;
  return sum;
}
int main() {
  long long x = 0, y = 0, a, b, c, d;
  cin >> a >> b;
  for (int i = 0; i < a; i++) cin >> ar[i];
  int p = 0;
  for (int i = a - 1; i >= 0; i--) x += ar[i] * pow1(b, p++);
  cin >> c >> d;
  for (int i = 0; i < c; i++) cin >> br[i];
  p = 0;
  for (int i = c - 1; i >= 0; i--) {
    y += br[i] * pow1(d, p++);
  }
  if (x == y) puts("=");
  if (x < y) puts("<");
  if (x > y) puts(">");
}
