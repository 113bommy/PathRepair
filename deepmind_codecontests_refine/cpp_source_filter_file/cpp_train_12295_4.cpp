#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  scanf("%lld %lld", &n, &m);
  if (m % n == 0)
    cout << n / m << endl;
  else
    cout << n / m + 1 << endl;
}
