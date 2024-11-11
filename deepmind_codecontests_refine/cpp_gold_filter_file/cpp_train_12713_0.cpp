#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, a, b, c;
  cin >> n >> k;
  if ((n * 2) % k == 0)
    a = (n * 2) / k;
  else
    a = ((n * 2) / k) + 1;
  if ((n * 5) % k == 0)
    b = (n * 5) / k;
  else
    b = ((n * 5) / k) + 1;
  if ((n * 8) % k == 0)
    c = (n * 8) / k;
  else
    c = ((n * 8) / k) + 1;
  cout << a + b + c;
  return 0;
}
