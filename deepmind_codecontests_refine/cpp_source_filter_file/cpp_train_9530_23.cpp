#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int flag[n];
  int f = 0;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    int n1, n2;
    cin >> n1 >> n2;
    if (n1 >= 2400 && n2 > n1)
      flag[i] = 1;
    else
      flag[i] = 0;
  }
  for (int i = 0; i < 3; i++) {
    if (flag[i] == 1) {
      cout << "YES" << endl;
      f = 1;
      break;
    }
  }
  if (f == 0) cout << "NO" << endl;
}
