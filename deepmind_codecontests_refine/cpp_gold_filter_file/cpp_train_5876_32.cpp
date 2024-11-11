#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, ans;
  cin >> a >> b;
  int alenth = a.length(), blenth = b.length(), flag = 0, counter = 0;
  if (alenth != blenth)
    flag = 0;
  else {
    for (int i = 0; i < a.length(); i++) {
      if (a[i] == b[blenth - 1]) {
        counter++;
      }
      blenth -= 1;
    }
    if (counter == alenth) flag = 1;
  }
  if (flag == 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
