#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int fl = -1, id = 1000000007;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > 1) {
        fl = i;
        id = min(fl, id);
      }
    }
    if (fl == -1) {
      if (n % 2 == 0)
        cout << "Second" << endl;
      else
        cout << "First" << endl;
    } else {
      ++id;
      if (id % 2 == 1) {
        cout << "First" << endl;
      } else
        cout << "Second" << endl;
    }
  }
}
