#include <bits/stdc++.h>
using namespace std;
int res[1003];
int main() {
  int n;
  cin >> n;
  int tot, prev;
  cout << "? " << 1 << " " << n << endl;
  cin >> tot;
  for (int i = n - 1; i >= 2; i--) {
    prev = tot;
    int x;
    cout << "? " << 1 << " " << i << endl;
    cin >> x;
    res[i + 1] = tot - x;
    tot = x;
  }
  int x;
  cout << "? " << 2 << " " << 3 << endl;
  cin >> x;
  res[1] = prev - x;
  res[2] = tot - res[1];
  cout << "!";
  for (int i = 1; i <= n; i++) cout << " " << res[i];
  cout << endl;
  return 0;
}
