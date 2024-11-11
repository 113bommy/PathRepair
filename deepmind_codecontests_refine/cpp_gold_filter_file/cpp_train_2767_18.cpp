#include <bits/stdc++.h>
using namespace std;
int main() {
  char aa[6][3] = {'0', '1', '2', '1', '0', '2', '1', '2', '0',
                   '2', '1', '0', '2', '0', '1', '0', '2', '1'};
  int n, x;
  cin >> n;
  cin >> x;
  int t = n % 6;
  char res = aa[t][x];
  cout << res << endl;
  return 0;
}
