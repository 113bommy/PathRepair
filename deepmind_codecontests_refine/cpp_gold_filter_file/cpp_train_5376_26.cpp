#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
  cin >> a >> b;
  if (a >= 30) {
    cout << b;
  } else {
    cout << (b % (1 << a));
  }
}
