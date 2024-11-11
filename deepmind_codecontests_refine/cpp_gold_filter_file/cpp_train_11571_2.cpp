#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, v;
  cin >> n >> v;
  if (v >= (n - 1))
    cout << n - 1;
  else {
    long long x = n - v;
    cout << v - 1 + (x * (x + 1)) / 2;
  }
  cout << "\n";
  return 0;
}
