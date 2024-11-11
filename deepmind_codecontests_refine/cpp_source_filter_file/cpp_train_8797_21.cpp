#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int c = 0;
  c += n / 5;
  n %= 5;
  c += n / 4;
  n %= 4;
  c += n / 3;
  n %= 3;
  c += n / 2;
  n %= 2;
  c += 1;
  cout << c;
  return 0;
}
