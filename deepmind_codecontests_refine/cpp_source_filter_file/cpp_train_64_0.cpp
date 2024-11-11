#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int t1 = 0;
  long long int tm1 = 0;
  long long int t2 = 0;
  long long int tm2 = 0;
  long long int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a <= 1000000 / 2) {
      t1 = a - 1;
      tm1 = max(t1, tm1);
    } else {
      t2 = 1000000 - a;
      tm2 = max(t2, tm2);
    }
  }
  cout << tm1 + tm2;
  return 0;
}
