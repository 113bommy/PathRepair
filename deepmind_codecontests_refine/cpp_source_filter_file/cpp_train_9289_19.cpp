#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if ((s[s.size() - 1] - 'a') % 2 == 0)
    cout << "0" << endl;
  else
    cout << "1" << endl;
}
