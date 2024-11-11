#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, n, m, i = 0, j = 0, p = 0, p1 = 0;
  cin >> n >> a >> b >> c >> d;
  i = c * 2;
  j = d * 2;
  p = n / a;
  p1 = n / b;
  i = i + (a * n);
  j = j + (b * n);
  p = i;
  p1 = j;
  if (p > p1) {
    puts("First");
  }
  if (p < p1) {
    puts("Second");
  }
  if (p == p1) {
    puts("Friendship");
  }
}
