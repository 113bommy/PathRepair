#include <bits/stdc++.h>
using namespace std;
int n, k, sum;
map<int, pair<int, int> > mp;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    vector<int> c(k);
    sum = 0;
    for (int j = 0; j < k; j++) {
      cin >> c[j];
      sum += c[j];
    }
    for (int j = 0; j < k; j++) {
      pair<int, int> x = mp[sum - c[j]];
      if (x.first != 0 && x.first != i + 1) {
        cout << "YES" << endl << x.first << " " << x.second << endl;
        cout << i + 1 << " " << j + 1;
        return 0;
      } else {
        mp[sum - c[j]] = {i + 1, j + 2};
      }
    }
  }
  cout << "NO";
}
