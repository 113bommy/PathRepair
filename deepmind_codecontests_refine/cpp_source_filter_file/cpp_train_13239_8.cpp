#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int i, flag = 0;
  for (i = 1; i < a.size(); i++) {
    if (a[i] == '1') {
      flag = 1;
      break;
    }
  }
  i = (a.size()) / 2;
  if (flag == 1 && a.size() / 2 == 1) i++;
  cout << i;
}
