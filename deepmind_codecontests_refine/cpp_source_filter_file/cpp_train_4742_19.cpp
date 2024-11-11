#include <bits/stdc++.h>
using namespace std;
int main() {
  string x;
  int r, c;
  cin >> r >> c;
  for (int i = 1; i <= r - 1; i++) cin >> x;
  cin >> x;
  int res = 0;
  for (int i = 0; i <= c - 1; i++)
    if (x[i] == 'B' && (i == 0 || x[i - 1] == ' ')) {
      res++;
    }
  cout << res << endl;
}
