#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> a >> b >> n;
  cout << abs(min(n - a, b + 1));
}
