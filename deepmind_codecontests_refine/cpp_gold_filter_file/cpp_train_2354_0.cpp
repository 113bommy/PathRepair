#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, f = 0;
  long long int i;
  cin >> n;
  for (i = n; i >= 1; i--) {
    cin >> x;
    if (x % 2 == 1) {
      f = 1;
    }
  }
  if (f) {
    cout << "First";
    return 0;
  }
  cout << "Second";
}
