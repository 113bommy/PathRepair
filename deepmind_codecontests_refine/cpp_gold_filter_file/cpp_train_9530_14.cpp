#include <bits/stdc++.h>
using namespace std;
int main() {
  short n, before, after;
  cin >> n;
  string a;
  bool flag = false;
  for (short i = 0; i < n; i++) {
    cin >> a;
    cin >> before;
    cin >> after;
    if (after >= 2400 && before >= 2400 && after - before > 0) flag = true;
  }
  if (flag == true)
    cout << "YES";
  else
    cout << "NO";
}
