#include <bits/stdc++.h>
using namespace std;
long long a, b, i;
long long ans = 0, val = 0;
int main() {
  cin >> a >> b;
  if (b == 1)
    cout << "0" << endl;
  else {
    for (i = 1; i <= a; i++) ans = (ans + i * b + 1) % 1000000007;
    for (i = 1; i < b; i++) {
      val = (val + ans * i) % 1000000007;
    }
    cout << val << endl;
  }
  return 0;
}
