#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  cout << (2 * b - 1 <= a ? 2 * b - 1 : 2 * b - a - a % 2);
}
