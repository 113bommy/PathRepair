#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int t = 0, o = 0;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    if (c == 2)
      t++;
    else
      o++;
  }
  if (t) {
    cout << 2 << " ";
    t--;
  } else {
    while (o--) {
      cout << 1 << " ";
    }
    return cout << endl, 0;
  }
  if (o) {
    cout << 1 << " ";
    o--;
  } else {
    while (t--) cout << 2 << " ";
    return cout << endl, 0;
  }
  while (t--) cout << 2 << " ";
  while (o--) cout << 1 << " ";
  cout << endl;
  return 0;
}
