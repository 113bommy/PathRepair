#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  int n;
  cin >> n >> a;
  int cnts = 0, cntf = 0;
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i] == 'F' && a[i + 1] == 'S') ++cntf;
    if (a[i] == 'S' && a[i + 1] == 'F') ++cnts;
  }
  if (cnts > cntf)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
