#include <bits/stdc++.h>
using namespace std;
const int BORDER = 100000;
long long x, k;
vector<vector<int>> divs;
vector<long long> A;
int cnt = 0;
void go(int v, int depth) {
  if (depth == k || v == 0) {
    cout << A[v] << " ";
    ++cnt;
    if (cnt > BORDER) exit(0);
    return;
  }
  for (size_t i = 0; i < divs[v].size(); ++i) {
    go(divs[v][i], depth + 1);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> x >> k;
  --k;
  if (x == 1) {
    cout << 1;
    return 0;
  }
  if (k > BORDER) {
    for (int i = 0; i < BORDER; ++i) cout << 1 << " ";
    return 0;
  }
  for (long long d = 1; d * d <= x; ++d) {
    if (x % d == 0) {
      A.push_back(d);
      if (d * d != x) A.push_back(x / d);
    }
  }
  sort(A.begin(), A.end());
  for (size_t i = 0; i < A.size(); ++i) {
    divs.push_back(vector<int>());
    for (size_t j = 0; j <= i; ++j)
      if (A[i] % A[j] == 0) divs.back().push_back(j);
  }
  go((int)A.size() - 1, -1);
  return 0;
}
