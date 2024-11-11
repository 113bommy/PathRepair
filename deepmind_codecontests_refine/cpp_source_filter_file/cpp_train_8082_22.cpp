#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int chan = 0;
  int le = 0;
  for (int i = 1; i <= n; i++) {
    int m;
    cin >> m;
    if (m % 2 == 0)
      chan++;
    else
      le++;
  }
  if (le <= chan) {
    cout << le << endl;
  } else {
    cout << chan + le / 3 << endl;
  }
}
