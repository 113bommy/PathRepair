#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, hash[256], var;
  char ar[] = {'R', 'P', 'S'}, x;
  string str;
  cin >> t;
  while (t--) {
    cin >> str;
    for (int i = 0; i < 3; i++) {
      hash[ar[i]] = 0;
    }
    for (int i = 0; i < str.size(); i++) {
      hash[str[i]]++;
    }
    var = 0;
    for (int i = 0; i < 3; i++) {
      if (hash[ar[i]] > var) {
        var = hash[ar[i]];
        x = ar[i];
      }
    }
    if (x == 'R') {
      x = 'P';
    } else if (x == 'S') {
      x = 'R';
    } else {
      x = 'S';
    }
    if (var == 1 && str.size() > 3) {
      for (int i = 0; i < 3; i++) {
        cout << ar[i];
      }
    } else {
      for (int i = 0; i < str.size(); i++) {
        cout << x;
      }
    }
    cout << '\n';
  }
  return 0;
}
