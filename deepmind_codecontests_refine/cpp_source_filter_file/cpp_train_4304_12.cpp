#include <bits/stdc++.h>
using namespace std;
long long xd(long long n) { return ((1 + (n - 1) * 12) * n) / 2; }
int main() {
  long long n;
  cin >> n;
  cout << xd(n) << endl;
  return 0;
}
