#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a;
  cin >> n;
  vector<int> v(8, 0);
  for (int i = (0); i <= (n - 1); i++) {
    cin >> a;
    v[a]++;
  }
  n /= 3;
  if (v[1] == n && v[2] + v[3] == n && v[4] + v[6] == n && v[3] <= v[6] &&
      v[4] <= v[2]) {
    while (v[4]--) {
      v[2]--;
      cout << "1 2 4"
           << "\n";
    }
    while (v[2]--) {
      v[6]--;
      cout << "1 2 6"
           << "\n";
    }
    while (v[3]--) {
      v[6]--;
      cout << "1 3 6"
           << "\n";
    }
  } else
    cout << -1;
}
