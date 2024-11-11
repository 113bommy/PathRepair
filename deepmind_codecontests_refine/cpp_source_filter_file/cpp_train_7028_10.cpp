#include <bits/stdc++.h>
using namespace std;
unsigned long long factorial(unsigned long long n) {
  unsigned long long res = 1, i;
  for (i = 1; i <= n; i++) res *= i;
  return res;
}
int main() {
  long long n, i, s = 1, c1 = 0;
  cin >> n;
  vector<int> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) c1++;
  }
  long long counter = 0, c2 = 0;
  bool k1 = false, k2 = false;
  if (c1 != 1)
    for (i = 0; i < n; i++) {
      if (a[i] == 1 && !k1) {
        k1 = true;
        c2 = i;
      } else if (a[i] == 1 && k1 == true) {
        counter = i - c2;
        c2 = i;
        s *= counter;
      }
    }
  else
    s = 1;
  cout << s << endl;
  return 0;
}
