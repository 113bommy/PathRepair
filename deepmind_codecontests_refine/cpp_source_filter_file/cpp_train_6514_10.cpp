#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
int main() {
  int a, b;
  cin >> a >> b;
  if (a == b || a + 1 == b || a - 1 == b || a + b == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
