#include <bits/stdc++.h>
using namespace std;
long long int fact(long int a) {
  long long int res = 1;
  for (int i = 1; i <= a; i++) {
    res = res * i;
  }
  return res;
}
int main() {
  long int a, b;
  cin >> a >> b;
  cout << fact(min(a, b)) << endl;
  return 0;
}
