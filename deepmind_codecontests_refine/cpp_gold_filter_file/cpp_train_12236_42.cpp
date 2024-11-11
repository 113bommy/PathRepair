#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
  cin >> n >> a >> b;
  cout << ((a - 1 + b) % n + n) % n + 1;
  return 0;
}
