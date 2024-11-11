#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e9 + 7;
const long long int inf = 1e18;
void solve() {
  long long int n;
  string a;
  cin >> a;
  vector<long long int> store;
  for (long long int i = 0; i < a.size(); i++) {
    if (i + 2 == a.size()) break;
    if (a[i] == 'o' and a[i + 1] == 'n' and a[i + 2] == 'e') {
      if (i - 2 >= 0) {
        if (a[i - 1] == 'w') {
          a[i] = '1';
          store.push_back(i);
        } else {
          a[i + 1] = '1';
          store.push_back(i + 1);
        }
      } else {
        a[i + 1] = '1';
        store.push_back(i + 1);
      }
    } else if (a[i] == 't' and a[i + 1] == 'w' and a[i + 2] == 'o') {
      if (i + 4 < a.size()) {
        if (a[i + 3] == 'n') {
          a[i + 2] = '1';
          store.push_back(i + 2);
        } else {
          a[i + 1] = '1';
          store.push_back(i + 1);
        }
      } else {
        a[i + 1] = '1';
        store.push_back(i + 1);
      }
    }
  }
  cout << store.size();
  cout << "\n";
  for (auto i : store) cout << i << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int q = 1;
  cin >> q;
  while (q--) {
    solve();
    cout << "\n";
  }
}
