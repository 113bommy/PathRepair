#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
void SADIEM() {
  std::ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
}
bool iscomposite(int x) {
  if (x < 2 || (x != 2 && !(x & 1)) || (x != 3 && !(x % 3)) ||
      (x != 5 && !(x % 3)))
    return true;
  for (int i = 7; i <= x / i; i++)
    if (!(x % i)) return true;
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, sum = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n && cin >> v[i].first; i++)
      v[i].second = i + 1, sum += v[i].first;
    if (iscomposite(sum)) {
      cout << n << "\n";
      for (int i = 0; i < n; i++) cout << i + 1 << (i < n - 1 ? " " : "");
    } else {
      sort(v.begin(), v.end());
      int idx = -1;
      for (int i = 0; i < n; i++) {
        if (iscomposite(sum - v[i].first)) {
          idx = i;
          break;
        }
      }
      cout << n - 1 << "\n";
      for (int i = 0; i < n; i++)
        if (idx != i) cout << v[i].second << " ";
    }
    if (t) cout << "\n";
  }
}
