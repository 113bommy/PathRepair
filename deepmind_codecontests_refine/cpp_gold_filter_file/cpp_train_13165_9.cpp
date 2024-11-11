#include <bits/stdc++.h>
using namespace std;
int xemxet(int r) {
  int s[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
  return (s[r]);
}
int main() {
  int s;
  cin >> s;
  cout << xemxet(s / 10) * xemxet(s % 10);
}
