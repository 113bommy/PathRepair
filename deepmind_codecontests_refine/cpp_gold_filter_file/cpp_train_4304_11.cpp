#include <bits/stdc++.h>
using namespace std;
long long xd(long long n) { return (((n - 1) * 12) * n) / 2 + 1; }
int main() {
  long long n;
  cin >> n;
  cout << xd(n) << endl;
  return 0;
}
