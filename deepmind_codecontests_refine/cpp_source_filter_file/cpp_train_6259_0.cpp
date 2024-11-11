#include <bits/stdc++.h>
using namespace std;
vector<int> v;
inline bool check(int i, int j) { return (2 * v[i] > v[j] && v[i] != 1); }
int main() {
  int n;
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  for (int i = 1; i < n; i++) {
    if (check(i - 1, i)) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
