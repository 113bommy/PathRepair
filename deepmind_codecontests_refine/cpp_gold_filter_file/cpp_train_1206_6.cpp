#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int j = 0, k = 0, l = 0, d = 0, L = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'h' && j == 0) {
      j++;
    } else if (str[i] == 'e' && j > 0) {
      k++;
    } else if (str[i] == 'i' && j > 0 && k > 0 && d == 0)
      l++;
    else if (str[i] == 'd' && j > 0 && k > 0 && l > 0)
      d++;
    else if (str[i] == 'i' && j > 0 && k > 0 && l > 0 && d > 0)
      L++;
  }
  if (j > 0 && k > 0 && l > 0 && d > 0 && L > 0)
    cout << "YES";
  else
    cout << "NO";
}
