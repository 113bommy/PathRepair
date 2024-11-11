#include <bits/stdc++.h>
using namespace std;
int main() {
  string in;
  char temp;
  int ct = 0, f1 = 0;
  getline(cin, in);
  for (int i = 0; i < in.length(); i++) {
    if (in[i] == temp) ct++;
    if (ct >= 7) f1 = 1;
    if (in[i] != temp) ct = 0;
    temp = in[i];
  }
  if (f1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
