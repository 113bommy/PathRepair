#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  long long p = 1;
  for (int i = 0; i < 18; i++) p *= 10;
  long long g = p / 10ll;
  long long a;
  cin >> a;
  a -= 5 * (9 * (g * 18 % a) % a) % a;
  cout << a << " " << p - 1 + a << endl;
  return 0;
}
