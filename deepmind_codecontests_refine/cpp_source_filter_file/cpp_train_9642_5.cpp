#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  int n;
  cin >> n >> a;
  int cnts = 0, cntf = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 'f' && a[i + 1] == 's') ++cntf;
    if (a[i] == 's' && a[i + 1] == 'f') ++cnts;
  }
  if (cnts > cntf)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
