#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string arr[62];
  for (int i = 0; i < 62; i++) {
    long long int as = pow(2, i);
    arr[i] = to_string(as);
  }
  int t;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    int nl = n.size();
    int diffmin = 20;
    for (int z = 0; z < 62; z++) {
      int j = 0;
      int diff = 0;
      for (int i = 0; i < nl; i++) {
        if (j < arr[z].size() && arr[z][j] == n[i])
          j++;
        else
          diff++;
      }
      diff += arr[z].size() - j;
      diffmin = min(diffmin, diff);
    }
    cout << diffmin << endl;
  }
}
