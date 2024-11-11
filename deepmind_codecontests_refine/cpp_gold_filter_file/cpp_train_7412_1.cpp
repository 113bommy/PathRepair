#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  while (n) {
    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (((a + b) % 3 == 0) && (a * 2 >= b)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    n--;
  }
  return 0;
}
