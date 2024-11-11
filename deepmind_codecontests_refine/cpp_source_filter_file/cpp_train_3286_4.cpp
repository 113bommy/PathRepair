#include <bits/stdc++.h>
using namespace std;
int main() {
  long long log, n;
  cin >> n;
  if (n % 2 == 0) {
    if (n == 2)
      cout << "1\n";
    else
      cout << "2\n";
  } else {
    int flag = 0;
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0) {
        flag = 1;
        break;
      }
    if (!flag) {
      cout << "1\n";
      return 0;
    }
    flag = 0;
    for (int i = 2; i * i <= n - 2; i++) {
      if (n % i == 0) {
        flag = 1;
        break;
      }
    }
    if (!flag)
      cout << "2\n";
    else
      cout << "3\n";
  }
}
