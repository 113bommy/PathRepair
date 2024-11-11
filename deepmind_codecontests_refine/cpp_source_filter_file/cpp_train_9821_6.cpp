#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main() {
  int a, b, c;
  vector<int> Fib;
  scanf("%d %d %d", &a, &b, &c);
  Fib.push_back(a);
  Fib.push_back(b);
  for (int i = 2; i < c; i++) Fib.push_back(Fib[i - 2] + Fib[i - 1]);
  printf("%d", Fib[c - 1]);
  return 0;
}
