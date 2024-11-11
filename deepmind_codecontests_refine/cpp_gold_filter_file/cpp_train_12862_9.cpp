#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  vector<string> vec(n);
  bool found = false;
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    if (found) continue;
    if (vec[i][0] == vec[i][1] && vec[i][1] == 'O') {
      vec[i][0] = '+';
      vec[i][1] = '+';
      found = true;
    } else if (vec[i][3] == vec[i][4] && vec[i][4] == 'O') {
      vec[i][3] = '+';
      vec[i][4] = '+';
      found = true;
    }
  }
  if (found) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << vec[i] << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
