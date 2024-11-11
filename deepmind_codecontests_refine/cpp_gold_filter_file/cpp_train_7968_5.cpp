#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a;
  cin >> a;
  long long int b, c;
  if (a == 1 || a == 2) {
    cout << -1;
    return 0;
  } else if (a % 2 != 0) {
    long long int num = a * a;
    b = (num - 1) / 2;
    c = b + 1;
  } else {
    long long int num = a * a;
    c = num / 4 + 1;
    b = c - 2;
  }
  cout << b << " " << c;
}
