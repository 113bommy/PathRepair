#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[19] = {2,  3,  5,  7,  11, 13, 17, 21, 23, 29,
               31, 37, 41, 43, 47, 4,  9,  25, 49};
  vector<int> v(a, a + 19);
  int cnt = 0;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
    string s;
    cin >> s;
    if (s == "yes") cnt++;
    s.clear();
  }
  if (cnt < 2)
    cout << "prime" << endl;
  else
    cout << "composite" << endl;
}
