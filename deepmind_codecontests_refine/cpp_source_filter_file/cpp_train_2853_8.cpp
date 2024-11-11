#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int M = 300005;
const int mod = 1e9 + 9;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
int a[N], n;
vector<pair<int, int> > ans;
void dfs(vector<pair<int, int> > &X) {
  sort(X.begin(), X.end());
  if (X[0].first == 0) return;
  int t = X[1].first / X[0].first;
  while (t) {
    if (t & 1)
      X[1].first -= X[0].first;
    else
      X[2].first -= X[0].first;
    X[0].first <<= 1;
    if (t & 1)
      ans.push_back(make_pair(X[0].second, X[1].second));
    else
      ans.push_back(make_pair(X[0].second, X[2].second));
    t >>= 1;
  }
  dfs(X);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  vector<pair<int, int> > A;
  for (int i = 0; i < n; i++) {
    if (a[i]) A.push_back(make_pair(a[i], i + 1));
    if (A.size() == 3) {
      dfs(A);
      vector<pair<int, int> > B;
      for (int i = 0; i < ((A).size()); i++)
        if (A[i].first) B.push_back(A[i]);
      swap(A, B);
    }
  }
  if (A.size() != 2)
    puts("-1");
  else {
    printf("%d\n", A.size());
    for (int i = 0; i < ((ans).size()); i++)
      printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
