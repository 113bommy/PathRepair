#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, flag = 0;
  cin >> n >> m;
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c;
      if (c == 'B' || c == 'W' || c == 'G')
        continue;
      else
        flag = 1;
    }
  }
  if (flag == 0)
    cout << "#Black&White" << endl;
  else
    cout << "#Color" << endl;
}
