#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, i = 0, flag = 0;
  cin >> n >> a >> b;
  while (n - b * i >= 0) {
    if ((n - b * i) % a == 0) {
      flag = 1;
      break;
    } else
      i++;
  }
  if (flag == 0) {
    i = 0;
    while (n - a * i >= 0) {
      if ((n - a * i) % b == 0) {
        flag = 1;
        break;
      } else
        i++;
    }
    if (flag == 1) {
      cout << "YES" << endl;
      cout << i << " " << (n - a * i) / b << endl;
    } else
      cout << "NO" << endl;
    return 0;
  } else {
    cout << "YES" << endl;
    cout << (n - b * i) / a << " " << i << endl;
  }
}
