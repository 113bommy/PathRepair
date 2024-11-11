#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, f = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int l, r, maxx = 0, minn = 1e9;
    if (n == 1) {
      cin >> l >> r;
      cout << 0 << '\n';
    } else {
      while (n--) {
        cin >> l >> r;
        if (l > maxx) maxx = l;
        if (r < minn) minn = r;
      }
      cout << max(0, abs(maxx - minn)) << '\n';
    }
  }
}
