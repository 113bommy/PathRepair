#include <bits/stdc++.h>
using namespace std;
int main() {
  string res;
  int a4, a7, a47, a74;
  cin >> a4 >> a7 >> a47 >> a74;
  if (a47 == a74) {
    if (a4 >= a47 + 1 && a7 >= a74) {
      for (int i = 0; i < a4 - a74; i++) res.push_back('4');
      for (int i = 0; i < a47; i++) res.append("47");
      for (int i = 0; i < a7 - a74; i++) res.push_back('7');
      res.push_back('4');
    } else if (a4 >= a47 && a7 >= a74 + 1) {
      res.push_back('7');
      for (int i = 0; i < a4 - a74; i++) res.push_back('4');
      for (int i = 0; i < a47; i++) res.append("47");
      for (int i = 0; i < a7 - a74 - 1; i++) res.push_back('7');
    } else
      goto impos;
  } else if (a47 == a74 + 1) {
    if (a4 >= a47 && a7 >= a47) {
      for (int i = 0; i < a4 - a47; i++) res.push_back('4');
      for (int i = 0; i < a47; i++) res.append("47");
      for (int i = 0; i < a7 - a47; i++) res.push_back('7');
    } else
      goto impos;
  } else if (a74 == a47 + 1) {
    if (a4 >= a47 && a7 >= a47) {
      res.push_back('7');
      for (int i = 0; i < a4 - a47 - 1; i++) res.push_back('4');
      for (int i = 0; i < a47; i++) res.append("47");
      for (int i = 0; i < a7 - a47 - 1; i++) res.push_back('7');
      res.push_back('4');
    } else
      goto impos;
  } else
    goto impos;
pos:
  cout << res << endl;
  return 0;
impos:
  cout << -1 << endl;
  return 0;
}
