#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, t, n1, n, n2, c = 0, d = 0;
  string s, s1, s2;
  vector<int> v, v1;
  cin >> t;
  n = t;
  while (t--) {
    cin >> s >> s1 >> s2;
    stringstream ss1(s1);
    ss1 >> n1;
    stringstream ss2(s2);
    ss2 >> n2;
    if (n1 >= 2400 && n1 < n2) c++;
  }
  if (c > n / 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
