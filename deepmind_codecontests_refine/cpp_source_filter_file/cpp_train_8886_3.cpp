#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int counter = 0;
  for (int i = 0; i < n; i++) {
    int j = 0;
    for (j = i + 1; j < n; j++) {
      if (s[j] == s[i])
        counter++;
      else {
        break;
      }
    }
    i = j;
  }
  cout << counter;
  return 0;
}
