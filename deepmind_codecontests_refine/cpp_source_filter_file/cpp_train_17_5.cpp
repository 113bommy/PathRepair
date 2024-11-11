#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int inf = 1e9 + 7;
bool compA(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.second) return a.second < b.second;
  return a.first > b.first;
}
bool comp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
void run() {
  int n, m, k, pos;
  cin >> n;
  vector<pair<int, int> > A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i].first;
    A[i].second = i;
  }
  cin >> m;
  sort(A.begin(), A.end(), compA);
  vector<vector<pair<int, int> > > B(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i + 1; ++j) B[i].push_back(A[j]);
    sort(B[i].begin(), B[i].end(), comp);
  }
  for (int i = 0; i < m; ++i) {
    cin >> k >> pos;
    cout << B[--k][--pos].first << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 0; i < t; ++i) {
    run();
  }
  return 0;
}
