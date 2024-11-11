#include <bits/stdc++.h>
using namespace std;
long Key[209], ans[209];
vector<vector<long> > mat;
int main(void) {
  long n, x;
  cin >> n;
  vector<pair<long, long> > q;
  for (long i = 0; i < 2 * n; i++) {
    cin >> x;
    q.push_back(make_pair(x, i));
  }
  sort(q.begin(), q.end());
  long idx = 0, prev = -1;
  for (long i = 0; i < 2 * n; i++) {
    if (i == 0 || (i != 0 && q[i].first != q[i - 1].first)) {
      Key[q[i].second] = idx;
      prev = idx++;
    } else if (i != 0 && q[i].first == q[i - 1].first) {
      Key[q[i].second] = prev;
    }
  }
  mat = vector<vector<long> >(idx);
  for (long i = 0; i < 2 * n; i++) {
    long ind = q[i].second;
    long a = Key[ind];
    mat[a].push_back(ind);
  }
  long u = 0, v = 0, k = 2;
  x = 1;
  for (long i = 0; i < idx; i++) {
    if (mat[i].size() == 1) {
      ans[mat[i][0]] = x;
      if (x == 1)
        u++;
      else
        v++;
      x = (x == 1) ? 2 : 1;
    } else {
      ans[mat[i][0]] = k;
      k = (k == 1) ? 2 : 1;
      ans[mat[i][1]] = k;
      k = (k == 1) ? 2 : 1;
      u++;
      v++;
      for (long j = 2; j < mat[i].size(); j++) {
        ans[mat[i][j]] = k;
        k = (k == 1) ? 2 : 1;
      }
    }
  }
  printf("%ld\n", u * v);
  for (long i = 0; i < 2 * n; i++) printf("%ld ", ans[i]);
  printf("\n");
  mat.clear();
  return 0;
}
