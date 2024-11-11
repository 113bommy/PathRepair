#include <bits/stdc++.h>
using namespace std;
long long res[5][5], n;
string a, b;
int main() {
  cin >> n;
  getline(cin, a);
  getline(cin, a);
  getline(cin, b);
  for (long long i = 0; i < n; i++) {
    if (a[i] == '0' && b[i] == '0') res[0][0]++;
    if (a[i] == '0' && b[i] == '1') res[0][1]++;
    if (a[i] == '1' && b[i] == '0') res[1][0]++;
    if (a[i] == '1' && b[i] == '1') res[1][1]++;
  }
  cout << res[0][0] * res[1][1] + res[0][0] * res[1][0] + res[0][1] * res[1][0]
       << endl;
  return 0;
}
