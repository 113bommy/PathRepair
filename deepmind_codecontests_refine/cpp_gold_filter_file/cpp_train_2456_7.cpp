#include <bits/stdc++.h>
using namespace std;
int num[100005];
int main() {
  int n, m;
  unsigned long long sum = 0;
  int min = 999999999;
  bool flag = true;
  while (cin >> n >> m) {
    min = 99999999999;
    sum = 0;
    flag = true;
    for (int i = 0; i < n; i++) {
      cin >> num[i];
      if (num[i] < min) min = num[i];
    }
    for (int i = 0; i < n; i++) {
      if ((num[i] - min) % m != 0) {
        flag = false;
        break;
      } else {
        sum += (num[i] - min) / m;
      }
    }
    if (flag)
      cout << sum << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
