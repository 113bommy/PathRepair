#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n = 0, x = 1;
  cin >> n;
  if (n == 0)
    cout << 1;
  else {
    for (int i = 1; i < n; i++) x = (x * 3) % 1000003;
  }
  cout << x;
}
