#include <bits/stdc++.h>
using namespace std;
const long long mxN = 1010;
long long n, a[mxN][mxN], row[mxN], col[mxN];
long long findrow(long long x) {
  for (long long i = x; i <= n; i++) {
    if (row[i] == 0) return i;
  }
  return x;
}
void swaprow(long long x1, long long x2) {
  for (long long i = 1; i <= n; i++) {
    swap(a[x1][i], a[x2][i]);
  }
}
long long findcol(long long y) {
  for (long long i = y; i <= n; i++) {
    if (col[i] == 0) return i;
  }
  return y;
}
void swapcol(long long y1, long long y2) {
  for (long long i = 1; i <= n; i++) swap(a[i][y1], a[i][y2]);
}
void redcol(long long x) {
  for (long long i = x; i <= n; i++) {
    if (a[x][i] == 1) col[i]--;
  }
}
void redrow(long long y) {
  for (long long i = y; i <= n; i++) {
    if (a[i][y] == 1) row[i]--;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  long long x, y;
  for (long long i = 1; i <= n - 1; i++) {
    cin >> x >> y;
    a[x][y] = 1;
    row[x]++;
    col[y]++;
  }
  vector<pair<long long, pair<long long, long long>>> ans;
  for (long long i = 1; i <= n; i++) {
    long long curr = findrow(i);
    if (curr != i) {
      ans.push_back(make_pair(1, make_pair(i, curr)));
      swap(row[i], row[curr]);
      swaprow(i, curr);
    }
    long long curc = findcol(i);
    if (curc != i) {
      ans.push_back(make_pair(2, make_pair(i, curc)));
      swap(col[i], col[curc]);
      swapcol(i, curc);
    }
    redcol(i);
    redrow(i);
  }
  cout << ans.size() << '\n';
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second.first << " "
         << ans[i].second.second << '\n';
  }
  return 0;
}
