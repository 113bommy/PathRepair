#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int h1, a1, c1;
  cin >> h1 >> a1 >> c1;
  long long int h2, a2;
  cin >> h2 >> a2;
  vector<string> s;
  int i = 0;
  while (h2 > 0) {
    if (h1 - a2 > 0) {
      h2 = h2 - a1;
      h1 = h1 - a2;
      s.push_back("STRIKE");
    } else {
      if (h2 - a1 <= 0) {
        i++;
        s.push_back("STRIKE");
        break;
      }
      h1 = h1 + c1 - a2;
      s.push_back("HEAL");
    }
    i++;
  }
  cout << i << endl;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    cout << s[i] << endl;
  }
}
