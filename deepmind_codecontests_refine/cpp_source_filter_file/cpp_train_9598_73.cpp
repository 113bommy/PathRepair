#include <bits/stdc++.h>
using namespace std;
int rev(int a, int b) { return a > b; }
int main() {
  int a, b, n;
  cin >> n >> a >> b;
  a = n - a;
  b = n - b;
  cout << n - max(a, b) + 1;
}
