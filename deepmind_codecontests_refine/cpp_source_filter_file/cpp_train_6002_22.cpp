#include <bits/stdc++.h>
using namespace std;
long long n, m, sum;
int main() {
  cin >> n >> m;
  if ((n * (n + 1) / 2) < m) m = m % (n * (n + 1) / 2);
  long long i = 1;
  while (1) {
    m -= i;
    if (m < i + 1) break;
    i++;
  }
  cout << m;
  return 0;
}
