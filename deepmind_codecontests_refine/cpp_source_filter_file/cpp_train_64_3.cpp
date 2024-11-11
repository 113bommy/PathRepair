#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, p = 0;
  cin >> n;
  vector<long long int> v;
  for (int i = 0; i < n; i++) {
    long long int a;
    cin >> a;
    if (a <= 50000)
      p = max(p, a - 1);
    else
      p = max(p, 1000000 - a);
  }
  cout << p;
  return 0;
}
