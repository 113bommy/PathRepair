#include <bits/stdc++.h>
using namespace std;
string str;
int jump(int start, int d) {
  int res = 0;
  for (int i = start; i < str.size() && str[i] == '*'; i += d, res++)
    ;
  return res;
}
int main() {
  int m;
  cin >> m;
  cin >> str;
  int n = str.size() / 2 + 1;
  int MAX = 0;
  for (int i = 0; i < str.size() && MAX < 5; i++) {
    for (int j = 1; j < n && MAX < 5; j++) {
      MAX = max(MAX, jump(i, j));
    }
  }
  if (MAX >= 5)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
}
