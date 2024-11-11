#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 100005;
vector<pair<int, int> > v[322];
int A[N], T[N], M[N], n, q, p, k, i, j;
int main() {
  for (cin >> n, i = 1; i <= n; i++) cin >> A[i];
  for (cin >> q, i = 1; i <= q; i++) {
    cin >> p >> k;
    if (k < 322)
      v[k].push_back(make_pair(p, i));
    else
      for (; p <= n; p += k + A[p]) T[i]++;
  }
  for (i = 1; i < 322; i++) {
    for (j = n; j; j--) M[j] = M[j + i + A[j]] + 1;
    for (j = 0; j < v[i].size(); j++) T[v[i][j].second] = M[v[i][j].first];
  }
  for (i = 1; i <= q; i++) cout << T[i] << " ";
  return 0;
}
