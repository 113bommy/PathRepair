#include <bits/stdc++.h>
using namespace std;
const int Mass = (int)2e5;
const double eps = (double)1e-9;
string mn[Mass], mx[Mass];
int main() {
  srand(time(NULL));
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  string s, q;
  int x;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s >> q;
    mx[i] = max(s, q);
    mn[i] = min(s, q);
  }
  string last = "";
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    if (last <= mn[x]) {
      last = mn[x];
    } else if (last <= mx[x]) {
      last = mx[x];
    } else {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
