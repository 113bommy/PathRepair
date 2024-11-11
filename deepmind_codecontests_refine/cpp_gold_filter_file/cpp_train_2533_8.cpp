#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, s;
  cin >> n;
  s = n;
  for (i = 2; i * i <= n;) {
    if (n % i == 0) {
      n /= i;
      s += n;
    } else
      i++;
  }
  if (n > 1) s++;
  cout << s << endl;
  return 0;
}
