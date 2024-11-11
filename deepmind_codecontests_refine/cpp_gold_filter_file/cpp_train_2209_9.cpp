#include <bits/stdc++.h>
using namespace std;
void read() {
  long long n, f = 0, even = 0;
  long long sum = 0, res = 0;
  cin >> n;
  if (n % 9) {
    cout << n / 9 * 10 + n % 9;
  } else {
    cout << n / 9 * 10 - 1;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) read();
  return 0;
}
