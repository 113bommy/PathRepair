#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n, x;
  while (t--) {
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    int teamselect = 0;
    int no_of_teams = 0;
    for (int i = n - 1; i >= 0; --i) {
      if ((n - teamselect - i) * a[i] >= x) {
        teamselect = n - i;
        no_of_teams++;
      }
    }
    cout << no_of_teams << "\n";
  }
  return 0;
}
