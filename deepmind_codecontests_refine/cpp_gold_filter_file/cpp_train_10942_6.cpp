#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long int s, a, b, c;
    cin >> s >> a >> b >> c;
    long long int r = s / c;
    r = r % a + (r / a) * (a + b);
    cout << r << endl;
  }
}
