#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  scanf("%lld %lld", &n, &m);
  if (m % n == 0)
    cout << m / n << endl;
  else
    cout << m / n + 1 << endl;
}
