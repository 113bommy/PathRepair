#include <bits/stdc++.h>
using namespace std;
long long a, b, c = 9999999, n, ans;
int main() {
  cin >> b;
  c = min(b, c);
  cin >> b;
  c = min(b, c);
  cin >> b;
  c = min(b, c);
  cin >> b;
  c = min(b, c);
  cin >> a >> n;
  if (c <= a)
    cout << 0 << endl;
  else {
    if (c >= n)
      cout << n - a << endl;
    else {
      cout << c - a << endl;
    }
  }
}
