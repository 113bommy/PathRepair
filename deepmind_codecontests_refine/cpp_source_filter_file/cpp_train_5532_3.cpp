#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  int f = 0, s = 0;
  while (n) {
    long long a = n % 10;
    if (a == 4) f++;
    if (a == 7) s++;
    n /= 10;
  }
  if (f == 4 || s == 7)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
