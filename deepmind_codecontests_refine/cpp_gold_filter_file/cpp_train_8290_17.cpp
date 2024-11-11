#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<string> v(10);
  for (int i = 0; i < 10; i++) {
    cin >> v[i];
  }
  string res = "";
  for (int i = 0; i <= 70; i += 10) {
    string find = s.substr(i, 10);
    for (int j = 0; j < 10; j++) {
      if (v[j] == find) {
        res.push_back(j + '0');
        break;
      }
    }
  }
  cout << res << endl;
  return 0;
}
