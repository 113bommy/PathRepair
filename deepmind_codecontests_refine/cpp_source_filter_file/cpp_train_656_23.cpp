#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 1;
  int a;
  int s = 0;
  while (cin >> a) {
    s += a * i;
    i++;
  }
  cout << s;
  return 0;
}
