#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, kk;
  string a, b;
  cin >> a >> b;
  if (a.size() != b.size())
    cout << "NO";
  else {
    k = 0;
    kk = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == '1') k++;
      if (b[i] = '1') kk++;
    }
    if (((k > 0) && (kk > 0)) || ((k == 0) && (kk == 0)))
      cout << "YES";
    else
      cout << "NO";
  }
}
