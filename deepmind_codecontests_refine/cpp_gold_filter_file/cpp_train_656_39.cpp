#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, s = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    s += i * x;
  }
  cout << s;
}
