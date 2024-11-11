#include <bits/stdc++.h>
using namespace std;
bool com(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  long long int maxx = 0, maxy = 0, maxarea = 0;
  double angle = 0;
  while (t--) {
    char c;
    cin >> c;
    long long int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    if (c == '+') {
      maxx = max(x, maxx);
      maxy = max(y, maxy);
    } else {
      if (x >= maxy && x >= maxx)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
