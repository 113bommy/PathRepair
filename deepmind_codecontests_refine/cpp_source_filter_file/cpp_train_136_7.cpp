#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c;
  cin >> a >> b >> c;
  if ((a * c) % b == 0) {
    cout << (((a * c) / b) - c);
  } else {
    cout << (((a * c) / b) - c - 1);
  }
  return 0;
}
