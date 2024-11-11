#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a = sqrt(n);
    long long b = a - 1 + (n - 1) / a;
    cout << b << endl;
  }
}
