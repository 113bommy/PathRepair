#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 1;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, i, q, a, b, ans = 0;
  cin >> n >> q;
  vector<int> one(n + 1);
  vector<int> two(n + 1);
  while (q--) {
    cin >> a >> b;
    if (a == 1) {
      if (one[b] == 0) {
        one[b] = 1;
        if (two[b] == 1) ans++;
        if (two[b + 1] == 1) ans++;
        if (two[b - 1] == 1) ans++;
      } else {
        one[b] = 0;
        if (two[b] == 1) ans--;
        if (two[b + 1] == 1) ans--;
        if (two[b - 1] == 1) ans--;
      }
    } else {
      if (two[b] == 0) {
        two[b] = 1;
        if (one[b] == 1) ans++;
        if (one[b + 1] == 1) ans++;
        if (one[b - 1] == 1) ans++;
      } else {
        two[b] = 0;
        if (one[b] == 1) ans--;
        if (one[b + 1] == 1) ans--;
        if (one[b - 1] == 1) ans--;
      }
    }
    if (ans == 0)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
