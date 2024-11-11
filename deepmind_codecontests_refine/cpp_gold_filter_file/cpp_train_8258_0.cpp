#include <bits/stdc++.h>
using namespace std;
int n;
int k, b;
set<long double> s;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k >> b;
    if (k != 0) s.insert((long double)b / k);
  }
  cout << (int)s.size() << endl;
  return 0;
}
