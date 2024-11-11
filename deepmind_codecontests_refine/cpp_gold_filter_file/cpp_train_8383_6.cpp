#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int a, b, c, d;
  cin >> a >> b;
  if (a % b == 0) {
    cout << (a) + b << endl;
  } else {
    c = a / b;
    c++;
    cout << c * b << endl;
  }
  return 0;
}
