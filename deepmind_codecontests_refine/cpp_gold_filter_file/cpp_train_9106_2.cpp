#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int l, j, ftemp, stemp;
  double temp;
  bool check = true;
  cin >> s >> l;
  temp = s.size() / double(l);
  l = s.size() / l;
  if (temp != l) check = false;
  for (int i = 0, j = l - 1; i < s.size() && check && j < s.size();
       i += l, j += l) {
    ftemp = i;
    stemp = j;
    while (ftemp < stemp) {
      if (s[ftemp] != s[stemp]) {
        check = false;
        break;
      }
      ftemp++;
      stemp--;
    }
    if (!check) break;
  }
  if (check)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
