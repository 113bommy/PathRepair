#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ret = 0;
  cin >> n, ret = n;
  for (int i = 2; i < sqrt(n); i++)
    while (n % i == 0) ret += n / i, n /= i;
  ret += (n > 1);
  cout << ret << endl;
  return 0;
}
