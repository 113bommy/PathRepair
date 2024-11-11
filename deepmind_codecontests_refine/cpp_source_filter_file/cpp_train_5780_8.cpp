#include <bits/stdc++.h>
using namespace std;
struct S {
  int i, b, w;
  inline bool operator<(S q) const { return (w != q.w ? w < q.w : b > q.b); }
};
inline void inc(int& i, int& j) {
  if (i + 1 < j)
    ++i;
  else {
    ++j;
    i = 1;
  }
}
int n, m;
S T[100000];
pair<int, int> R[100000];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int a = 0; a < m; ++a) {
    cin >> T[a].w >> T[a].b;
    T[a].i = a;
  }
  sort(T, T + m);
  int i = 1, j = 1, k = 0;
  for (int a = 0; a < n; ++a) {
    if (!T[a].b) {
      inc(i, j);
      if (j > k) {
        cout << -1;
        return 0;
      }
      R[T[a].i] = make_pair(i, j);
    } else {
      ++k;
      R[T[a].i] = make_pair(0, k);
    }
  }
  for (int a = 0; a < n; ++a) {
    cout << R[a].first + 1 << " " << R[a].second + 1 << "\n";
  }
  return 0;
}
