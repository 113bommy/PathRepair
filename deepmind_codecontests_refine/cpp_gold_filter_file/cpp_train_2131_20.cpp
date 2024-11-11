#include <bits/stdc++.h>
using namespace std;
bool check(long long a) {
  a = abs(a);
  while (a) {
    if (a % 10 == 8) return true;
    a /= 10;
  }
  return false;
}
int main() {
  long long k;
  cin >> k;
  k++;
  int tot = 1;
  while (!check(k)) {
    tot++;
    k++;
  }
  cout << tot << endl;
  return 0;
}
