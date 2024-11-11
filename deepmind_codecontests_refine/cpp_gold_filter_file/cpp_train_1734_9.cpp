#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
vector<int> solve(vector<int> mst, int itr) {
  sort(mst.begin(), mst.end());
  mst.resize(unique(mst.begin(), mst.end()) - mst.begin());
  if (itr == 21) return vector<int>(21, 0);
  if (mst.empty()) return vector<int>();
  bool ok = true;
  for (int x : mst)
    if (x % 2) ok = false;
  if (ok) {
    vector<int> aux;
    for (int x : mst)
      if (x / 2) aux.push_back(x / 2);
    return solve(aux, itr + 1);
  }
  vector<int> ans(21, 0);
  for (int v : {-1, 1}) {
    vector<int> aux;
    for (int x : mst) {
      if (x % 2) {
        if ((x - v) / 2) aux.push_back((x - v) / 2);
      } else if (x / 2)
        aux.push_back(x / 2);
    }
    vector<int> axv = solve(aux, itr + 1);
    axv.push_back(v * (1 << itr));
    if (axv.size() < ans.size()) ans = axv;
  }
  return ans;
}
int main(void) {
  int n;
  scanf("%d", &n);
  vector<int> mst;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    mst.push_back(x);
  }
  vector<int> ans = solve(mst, 0);
  printf("%d\n", (int)ans.size());
  for (int x : ans) printf("%d ", x);
  return 0;
}
