#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n & 1)
    cout << 0;
  else
    cout << (1 << (n / 2));
  return 0;
}
