#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int countl = 1;
    int countr = 1;
    for (int j = i; j < n - 1; j++) {
      if (s[j] == 'L')
        countl++;
      else if (s[j] == '=') {
      } else
        break;
    }
    for (int j = i - 1; j >= 0; j++) {
      if (s[j] == 'R')
        countr++;
      else if (s[j] == '=') {
      } else
        break;
    }
    cout << max(countl, countr) << " ";
  }
}
