#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a;
  cin >> a;
  a = (n - a) % n;
  bool flag = false;
  for (int i = 1; i < n; i++) {
    int temp;
    cin >> temp;
    if (flag == true) {
      if (!((a + temp) % n == i)) {
        cout << "No";
        return 0;
      }
      flag = false;
    } else {
      int neg = temp - a;
      if (neg < 0) neg = n + neg;
      if (!((neg) % n == i)) {
        cout << "No";
        return 0;
      }
      flag = true;
    }
  }
  cout << "Yes";
  return 0;
}
