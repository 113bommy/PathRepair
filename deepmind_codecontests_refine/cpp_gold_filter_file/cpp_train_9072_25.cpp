#include <bits/stdc++.h>
using namespace std;
const int base = 13331;
const int MX = 1e5 + 7;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
struct node {
  int x, y;
};
vector<node> v;
int main() {
  int n;
  cin >> n;
  int l = 1, r = 1;
  int ans = 1;
  v.push_back((node){1, 1});
  for (int i = 2; i <= n; ++i) {
    if (i % 2 == 0) {
      r++;
    } else {
      l++;
    }
    ans = max(l, r);
    v.push_back((node){l, r});
  }
  cout << ans << endl;
  for (int i = 0; i < n; ++i) {
    cout << v[i].x << " " << v[i].y << endl;
  }
  return 0;
}
