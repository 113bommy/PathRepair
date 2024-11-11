#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 15;
int n;
int main() {
  cin >> n;
  if (n % 3 == 1) n--;
  if (n % 3 == 2) n += 1;
  int m = n / 36;
  cout << m;
  n -= m * 36;
  cout << " " << n / 3;
}
