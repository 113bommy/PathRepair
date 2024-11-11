#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    cout << (a + b + c) / 2 << endl;
  }
  return 0;
}
