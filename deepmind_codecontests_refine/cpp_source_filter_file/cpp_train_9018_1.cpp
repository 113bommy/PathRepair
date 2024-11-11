#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return (a.first < b.first);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long x, y, t, c;
  cin >> x >> y;
  if (y == 0) {
    cout << "No" << endl;
    return 0;
  }
  if (y == 1) {
    if (x > 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  t = y - 1;
  t = x - t;
  if (t % 2 == 0 && t > 0) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
