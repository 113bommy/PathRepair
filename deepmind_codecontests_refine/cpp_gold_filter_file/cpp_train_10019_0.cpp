#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[n], temp, flag = 0, n1 = n;
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> pos;
    for (int i = 0; i < n; i++) {
      pos[a[i]] = i + 1;
    }
    temp = pos[1];
    for (int i = 2; i <= n; i++) {
      if (temp != n1) {
        if (pos[i] != temp + 1) {
          flag = 1;
          break;
        } else
          temp = pos[i];
      } else {
        temp = pos[i];
        n1 = n - i + 1;
      }
    }
    if (flag == 1)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  return 0;
}
