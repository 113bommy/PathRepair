#include <bits/stdc++.h>
int main() {
  using namespace std;
  int a, b;
  int c = 0;
  int d = 0;
  int e = 0;
  cin >> a >> b;
  if (a > b) {
    c = b;
    d = (a - b) / 2;
  }
  if (b > a) {
    c = a;
    d = (b - a) / 2;
  }
  if (a == b) c = a;
  cout << c << " " << d;
}
