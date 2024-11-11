#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  int flag = 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      if (n > 1) {
        flag = 1;
        break;
      } else {
        flag = i;
        break;
      }
    }
    if (!flag) break;
  }
  if (flag == 0)
    cout << n << endl;
  else
    cout << flag << endl;
}
