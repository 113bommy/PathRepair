#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b) { return (a > b); }
template <typename T>
void print_arr(vector<T> &arr) {
  int s = int((arr).size()), i;
  for (i = 0; i < s; i++) cout << arr[i] << ' ';
  cout << '\n';
}
template <typename T>
int getMax(multiset<T> st) {
  if (int((st).size()) == 0) return 0;
  return *st.begin();
}
int main() {
  ios_base::sync_with_stdio(false);
  int i, j;
  int n;
  cin >> n;
  ;
  int m;
  cin >> m;
  ;
  int k;
  cin >> k;
  ;
  vector<vector<int> > mat(n, vector<int>(m));
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) cin >> mat[i][j];
  vector<multiset<int, bool (*)(int, int)> > vpq(
      m, multiset<int, bool (*)(int, int)>(&comp));
  int start = 0, end = 0;
  vector<int> mxs(m);
  int ans = 0;
  vector<int> ans_arr;
  while (end < n) {
    int tot = 0;
    for (i = 0; i < m; i++) {
      if (int((vpq[i]).size()) == 0) {
        ;
        mxs[i] = mat[end][i];
      } else
        mxs[i] = max(mat[end][i], *vpq[i].begin());
      tot += mxs[i];
    }
    if (tot <= k) {
      for (i = 0; i < m; i++) vpq[i].insert(mat[end][i]);
      end++;
      int tans = end - start;
      if (tans > ans) {
        ans_arr = mxs;
        ans = tans;
      }
      continue;
    }
    for (i = 0; i < m; i++) {
      vpq[i].erase(mat[start][i]);
    }
    start++;
    if (start > end) end = start;
  };
  print_arr(ans_arr);
}
