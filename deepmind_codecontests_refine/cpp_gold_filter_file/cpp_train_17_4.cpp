#include <bits/stdc++.h>
using namespace std;
int bsl(vector<pair<int, int>> &A, int val) {
  int left = -1;
  int right = (int)A.size();
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (A[mid].first >= val) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return right;
}
int bsr(vector<pair<int, int>> &A, int val) {
  int left = 0;
  int right = (int)A.size() + 1;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (A[mid].first <= val) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return left;
}
int main() {
  int n;
  cin >> n;
  vector<int> N(n);
  vector<pair<int, int>> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> N[i];
    A[i] = {N[i], i};
  }
  sort(A.begin(), A.end());
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int k, pos;
    cin >> k >> pos;
    int val = A[n - k].first;
    set<int> S;
    int r = bsr(A, val);
    int l = bsl(A, val);
    int val1 = n - r - 1;
    int val2 = k - val1;
    for (int j = l; j < l + val2; ++j) {
      S.insert(A[j].second);
    }
    for (int j = r + 1; j < n; ++j) {
      S.insert(A[j].second);
    }
    auto itr = S.begin();
    advance(itr, pos - 1);
    cout << N[*itr] << endl;
  }
}
