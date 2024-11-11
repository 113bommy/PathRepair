#include <bits/stdc++.h>
using namespace std;
const int MAX_ELEMENT = 100000;
int main() {
  int i, j;
  int N, M;
  int s, e;
  cin >> N >> M >> s >> e;
  vector<int> a(N), b(M);
  vector<int> indexes[MAX_ELEMENT + 2];
  for (i = 0; i < N; i++) cin >> a[i];
  for (i = 0; i < M; i++) {
    cin >> b[i];
    indexes[b[i]].push_back(i);
  }
  int lim = s / e + 1;
  int ans = 0;
  vector<int> d(lim + 1, 1E9);
  d[0] = -1;
  for (i = 0; i < N; i++) {
    for (j = lim; j >= 1; j--) {
      int k =
          upper_bound(indexes[a[i]].begin(), indexes[a[i]].end(), d[j - 1]) -
          indexes[a[i]].begin();
      if (k < indexes[a[i]].size()) {
        int num = indexes[a[i]][k];
        d[j] = min(d[j], num);
        if (e * j + num + 1 + i + 1 <= s) ans = max(ans, j);
      }
    }
  }
  cout << ans << endl;
}
