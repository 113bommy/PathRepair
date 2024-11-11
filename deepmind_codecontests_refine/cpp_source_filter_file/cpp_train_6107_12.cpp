#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int flag = 0;
  int l = a.size();
  for (int j = 0; j < l - 1; j++) {
    if (a[j] == a[j + 1]) {
      flag++;
    } else if (a[j] != a[j + 1]) {
      flag = 0;
    }
    if (flag == 7) {
      cout << "YES" << endl;
      break;
    }
  }
  if (flag != 7) {
    cout << "NO" << endl;
  }
  return 0;
}
