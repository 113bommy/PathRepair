#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  long long int a, b, c, alice;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b >> c;
    alice = (a + b + c) / 2;
    cout << alice << endl;
  }
  return 0;
}
