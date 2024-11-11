#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, c;
  cin >> a >> b >> c >> n;
  long long int total = n - (a + b - c);
  if (a + b < c || total <= 0 || a < c || b < c) {
    cout << "-1" << endl;
  } else {
    cout << total;
  }
  return 0;
}
