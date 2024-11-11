#include <bits/stdc++.h>
using namespace std;
const int inf = 9e16;
char ch1, ch2, ch3;
long long minn = inf;
long long a, b, c, d;
void f(long long a, long long b) {
  long long k;
  if (ch3 == '+')
    k = a + b;
  else
    k = a * b;
  if (k < minn) minn = k;
}
void f2(long long a, long long b, long long c) {
  if (ch2 == '+') {
    f(a + b, c);
    f(a + c, b);
    f(b + c, a);
  } else {
    f(a * b, c);
    f(a * c, b);
    f(b * c, a);
  }
}
void f3(long long a, long long b, long long c, long long d) {
  if (ch1 == '+') {
    f2(a + b, c, d);
    f2(a + c, b, d);
    f2(a + d, b, c);
    f2(b + c, a, d);
    f2(b + d, a, c);
    f2(c + d, a, b);
  } else {
    f2(a * b, c, d);
    f2(a * c, b, d);
    f2(a * d, b, c);
    f2(b * c, a, d);
    f2(b * d, a, c);
    f2(c * d, a, b);
  }
}
int main() {
  cin >> a >> b >> c >> d;
  cin >> ch1 >> ch2 >> ch3;
  f3(a, b, c, d);
  cout << minn << endl;
  return 0;
}
