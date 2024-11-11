#include <bits/stdc++.h>
using namespace std;
long long n, k, p;
long long x;
int main() {
  cin >> n >> k >> p;
  for (int i = 0; i < n; i++) {
    bool flag;
    cin >> x;
    x--;
    x = (n - 1) - x;
    if (n % 2 == 0) {
      if (x % 2 == 0) {
        flag = (x / 2 + 1) <= k;
      } else {
        flag = (x / 2 + 1) <= (k - n / 2);
      }
    } else {
      if (x == 0)
        flag = k > 0;
      else if (x == 1)
        flag = k > 1;
      else {
        if (x % 2 == 1) {
          flag = (x - 1) / 2 <= (k - 2);
        } else {
          flag = x / 2 <= (k - 1 - n / 2);
        }
      }
    }
    if (flag)
      cout << "X";
    else
      cout << ".";
  }
  cout << endl;
}
