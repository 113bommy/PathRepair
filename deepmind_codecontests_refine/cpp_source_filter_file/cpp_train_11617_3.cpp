#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
bool compare(T x, U y) {
  return (abs(x - y) <= 1e-9);
}
const int MOD = 1e9 + 7;
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  vector<int> v;
  cin >> n;
  int ini = n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  vector<int> freq(n + 5);
  for (int i = 0; i < n; i++) {
    if (ini == v[i]) {
      cout << ini << " ";
      ini--;
      while (ini > 0 && freq[ini]) {
        cout << ini << " ";
        freq[ini] = 0;
        ini--;
      }
      cout << "\n";
    } else {
      freq[v[i]] = 1;
      cout << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
