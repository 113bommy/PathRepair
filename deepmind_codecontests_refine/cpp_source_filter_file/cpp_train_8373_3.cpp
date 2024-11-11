#include <bits/stdc++.h>
using namespace std;
int a['Z' + 1], b['Z' + 1];
string x, y;
int main() {
  getline(cin, x);
  for (int i = 0; i < x.size(); i++) a[x[i]]++;
  getline(cin, y);
  for (int i = 0; i < y.size(); i++) b[y[i]]++;
  bool ok = true;
  for (int i = 'a'; i <= 'z'; i++)
    if (a[i] < b[i]) ok = false;
  for (int i = 'A'; i <= 'Z'; i++)
    if (a[i] < b[i]) ok = false;
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
