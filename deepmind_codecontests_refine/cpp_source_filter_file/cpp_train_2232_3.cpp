#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4], a1, a2, a3, a4, sum = 0, k;
  cin >> a1 >> a2 >> a3 >> a4;
  a[1] = a1;
  a[2] = a2;
  a[3] = a3;
  a[4] = a4;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    k = s[i] - 48;
    sum = sum + a[k];
  }
  cout << sum << endl;
}
