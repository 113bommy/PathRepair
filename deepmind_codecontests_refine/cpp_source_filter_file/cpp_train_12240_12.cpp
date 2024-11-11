#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, m, k;
  cin >> n >> m >> k;
  unsigned long long r = (k / 2) / m + 1;
  unsigned long long d = (k / 2) % m + 1;
  char s;
  if (k & 1)
    s = 'L';
  else
    s = 'R';
  cout << r << " " << d << " " << char(s);
  return 0;
}
