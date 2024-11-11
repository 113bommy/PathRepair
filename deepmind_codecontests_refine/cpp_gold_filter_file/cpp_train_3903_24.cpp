#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0;
  string m;
  cin >> m;
  for (int i = 1; i < m.length(); i++) sum += pow(2, i);
  int j = 0;
  for (int i = (m.length() - 1); i >= 0; i--) {
    if (m[i] == '7') sum += pow(2, j);
    j++;
  }
  sum++;
  cout << sum << endl;
  return 0;
}
