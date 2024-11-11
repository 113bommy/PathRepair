#include <bits/stdc++.h>
using namespace std;
int main() {
  long long c, i = 1;
  cin >> c;
  while (i < c) {
    c -= i;
    i++;
  }
  cout << c;
  return 0;
}
