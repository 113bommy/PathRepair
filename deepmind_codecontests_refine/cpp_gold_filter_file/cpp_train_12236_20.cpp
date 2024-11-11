#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  a = a + b;
  a = a % n;
  if (a <= 0) a = n + a;
  cout << a;
}
