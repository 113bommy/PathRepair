#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r;
  cin >> n >> r;
  long double val;
  val = (long double)sin(3.14159265 / n);
  double rad = val * r / (1 - val);
  printf("%.7llf", rad);
}
