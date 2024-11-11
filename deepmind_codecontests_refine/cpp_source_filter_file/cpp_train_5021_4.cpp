#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, sum = 0, c = 0;
  string s;
  cin >> t;
  cin >> s;
  for (int i = 0; i < t; i++) {
    if (s[i] == '(') {
      sum += 1;
      if (sum <= 0) c++;
    } else {
      sum += -1;
      if (sum < 0) c++;
    }
  }
  if (sum != 0)
    cout << "NO";
  else
    cout << c;
}
