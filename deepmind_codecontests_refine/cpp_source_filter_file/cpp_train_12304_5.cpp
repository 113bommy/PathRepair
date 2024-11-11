#include <bits/stdc++.h>
using namespace std;
vector<long long> primes;
bool np[int(1e7 + 1)];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a, b;
  cin >> a >> b;
  if (a == 9 && b == 1)
    cout << 9 << " " << 10 << endl;
  else if (abs(a - b) > 1)
    cout << -1 << endl;
  else if (a == b) {
    cout << a << 1 << " " << a << 2 << endl;
  } else
    cout << a << 9 << " " << b << 0 << endl;
}
