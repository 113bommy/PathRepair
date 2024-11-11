#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, count;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    if (a + b + c >= 2) {
      count++;
    }
  }
  cout << count;
  return 0;
}
