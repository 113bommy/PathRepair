#include <bits/stdc++.h>
using namespace std;
long long to(int i) {
  long long s = 0, t = 1;
  while (i) {
    s += (i & 1) * t;
    t *= 10;
    i = i >> 1;
  }
  return s;
}
int main() {
  long long n, s = 0, i = 1;
  cin >> n;
  for (i = 1; i < 1000; i++)
    if (to(i) > n) break;
  cout << i - 1;
}
