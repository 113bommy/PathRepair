#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, n, x, sum = 0;
  set<long long> v;
  map<long long, long long> mp;
  set<long long>::iterator it;
  cin >> n >> x;
  if (n == 1 && x == 10)
    cout << -1 << endl;
  else if (x < 10) {
    for (i = 0; i < n; i++) cout << x;
    cout << endl;
  } else {
    cout << 1 << endl;
    for (i = 1; i < n; i++) cout << 0;
    cout << endl;
  }
  return 0;
}
