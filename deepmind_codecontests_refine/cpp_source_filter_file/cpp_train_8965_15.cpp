#include <bits/stdc++.h>
using namespace std;
int fre[1005];
int main() {
  ios_base ::sync_with_stdio(0);
  long long int q;
  cin >> q;
  while (q--) {
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c >= a) {
      cout << a << " " << d << "\n";
    } else {
      cout << c << " " << b << "\n";
    }
  }
}
