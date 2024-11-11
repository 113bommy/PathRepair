#include <bits/stdc++.h>
using namespace std;
int x, g[4];
pair<int, int> a[4];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a[1].first >> a[2].first >> a[3].first;
  a[1].second = 1;
  a[2].second = 2;
  a[3].second = 3;
  sort(a + 1, a + 4);
  g[a[1].second] = 1;
  g[a[2].second] = 2;
  g[a[3].second] = 3;
  cout << "First\n"
       << a[3].first + a[3].first - a[1].first - a[2].first << endl;
  cin >> x;
  if (g[x] == 1) {
    cout << a[3].first - a[2].first << endl;
    cin >> x;
    assert(x == 0);
  } else if (g[x] == 2) {
    cout << a[3].first - a[1].first << endl;
    cin >> x;
    assert(x == 0);
  } else {
    a[3].first += a[3].first + a[3].first - a[1].first - a[2].first;
    cout << a[3].first + a[3].first - a[1].first - a[2].first << endl;
    cin >> x;
    if (g[x] == 1) {
      cout << a[3].first - a[2].first << endl;
      cin >> x;
      assert(x == 0);
    } else if (g[x] == 2) {
      cout << a[3].first - a[1].first << endl;
      cin >> x;
      assert(x == 0);
    }
  }
  return 0;
}
