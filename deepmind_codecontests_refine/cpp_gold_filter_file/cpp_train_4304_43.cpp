#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int a, s = 0, i;
  cin >> a;
  for (i = 1; i <= a; i++) {
    s = s + i - 1;
  }
  cout << s * 12 + 1 << endl;
  ;
  return 0;
}
