#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sub;
  int grp;
  cin >> n >> sub;
  if (n == sub)
    grp = 0;
  else if (sub == 0 || sub == 1)
    grp = 1;
  else if (sub >= n / 2)
    grp = n - sub;
  else
    grp = sub;
  cout << grp << endl;
}
