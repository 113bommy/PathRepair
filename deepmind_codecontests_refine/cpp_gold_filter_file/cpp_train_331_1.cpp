#include <bits/stdc++.h>
using namespace std;
void ini() {}
bool check(unsigned long long int n, unsigned long long int m,
           unsigned long long int x) {
  unsigned long long int res = n * m, temp;
  while (m != 0) {
    temp = m;
    m = n % m;
    n = temp;
  }
  if ((res / n) == x) {
    return true;
  } else {
    return false;
  }
}
int main() {
  ini();
  unsigned long long int x, d;
  cin >> x;
  d = sqrt(x);
  unsigned long long int a = 2, temp, m = x;
  while (a <= d) {
    if (x % a == 0 && check(x / a, a, x)) {
      temp = max(x / a, a);
      m = min(m, temp);
    }
    a++;
  }
  cout << m << " " << x / m;
}
