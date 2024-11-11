#include <bits/stdc++.h>
using namespace std;
const int N = 201010;
int main() {
  ios_base::sync_with_stdio(0);
  int test;
  cin >> test;
  while (test--) {
    int n, a, b;
    cin >> a >> b >> n;
    int f[5] = {a, b, a ^ b, a, b};
    cout << f[n % 5] << endl;
  }
  return 0;
}
