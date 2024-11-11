#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  ll r = 0;
  if (n % 2 == 0) {
    while (n) {
      r += n / 10;
      n /= 10;
    }
  }
  cout << r << endl;
}
