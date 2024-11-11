#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int n;
  cin >> n;
  long long int a;
  cin >> a;
  long long int b;
  cin >> b;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    cout << ((x * a) % b) / x << " ";
  }
}
