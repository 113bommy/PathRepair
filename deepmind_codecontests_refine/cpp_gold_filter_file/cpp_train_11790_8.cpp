#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> is_married(n + 1), prince(n + 1);
    for (int i = 1; i <= n; i++) {
      int k;
      cin >> k;
      int p = INT_MAX;
      for (int j = 0; j < k; j++) {
        int curr_prince;
        cin >> curr_prince;
        if (!prince[curr_prince]) p = min(p, curr_prince);
      }
      if (p != INT_MAX) {
        prince[p] = 1;
        is_married[i] = 1;
      }
    }
    int pcess = 0, pnce = 0;
    for (int i = 1; i <= n; i++) {
      if (is_married[i] == 0) {
        pcess = i;
        for (int j = 1; j <= n; j++)
          if (prince[j] == 0) {
            pnce = j;
            break;
          }
        break;
      }
    }
    if (pcess) {
      cout << "IMPROVE\n";
      cout << pcess << ' ' << pnce << endl;
    } else
      cout << "OPTIMAL\n";
  }
}
