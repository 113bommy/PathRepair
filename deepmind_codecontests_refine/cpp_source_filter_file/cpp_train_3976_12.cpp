#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, strenth, inte, a, exp;
  cin >> t;
  a = 0;
  while (t) {
    cin >> strenth >> inte >> exp;
    if (strenth + exp <= inte) {
      cout << a << endl;
      t--;
      continue;
    }
    if (inte + exp <= strenth) {
      cout << exp + 1 << endl;
      t--;
      continue;
    }
    cout << (exp + strenth - inte + 1) / 2 << endl;
    t--;
  }
}
