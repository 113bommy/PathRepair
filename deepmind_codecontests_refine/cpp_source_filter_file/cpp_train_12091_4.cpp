#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n{}, m{}, k{}, i{}, out{}, f{}, sec{};
  cin >> n >> m >> k;
  while (n--) {
    cin >> i;
    if (i > f) {
      f = i;
      sec = f;
    } else if (i > sec)
      sec = i;
  }
  i = m / (k + 1);
  out += i * ((k * f) + sec);
  if (m % (k + 1) != 0) {
    out += (m % (k + 1)) * f;
  }
  cout << out << '\n';
  return 0;
}
