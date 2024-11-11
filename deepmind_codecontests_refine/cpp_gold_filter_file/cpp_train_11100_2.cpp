#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long pla, num, a, b, cnt = 0;
  cin >> a;
  for (long long i = 1; i < n; i++) {
    cin >> b;
    if (a > b)
      cnt++;
    else
      cnt = 1, a = b;
    if (a == n or cnt == k) {
      cout << a << endl;
      break;
    }
  }
}
