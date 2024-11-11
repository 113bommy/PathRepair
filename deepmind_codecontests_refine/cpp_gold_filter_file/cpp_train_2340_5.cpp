#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, c, l[maxn], r[maxn][2];
vector<int> res;
void no() {
  cout << "IMPOSSIBLE\n";
  exit(0);
}
int build(int b, int e, int x) {
  if (x < b) {
    return b - 1;
  } else if (e < x) {
    no();
  } else if (b == e) {
    if (l[b] > 0 || r[b][0] > 0) {
      no();
    }
    res.push_back(b);
    return b;
  } else {
    int left = build(b + 1, e, l[b]);
    res.push_back(b);
    if (0 < r[b][0] && r[b][0] <= left) {
      no();
    }
    if (x <= left) {
      if (r[b][0] == 0) {
        return left;
      } else if (left == e) {
        no();
      }
    }
    return build(left + 1, e, max(r[b][1], x));
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> c;
  for (int i = 0; i < c; i++) {
    int a, b;
    string dir;
    cin >> a >> b >> dir;
    if (b <= a) {
      no();
    }
    if (dir[0] == 'L') {
      l[a] = max(b, l[a]);
    } else {
      if (r[a][0] == 0) {
        r[a][0] = b;
      }
      r[a][0] = min(b, r[a][0]);
      r[a][1] = max(b, r[a][1]);
    }
  }
  build(1, n, n);
  for (int i = 0; i < n; i++) {
    cout << res[i];
    if (i < n - 1) {
      cout << ' ';
    }
  }
  cout << '\n';
  return 0;
}
