#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    sum = (a + b + c) / 2;
    cout << sum;
  }
}
