#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.first - b.first < b.first - b.second;
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie();
  cout.tie();
  long long int n, ans = 0;
  cin >> n;
  vector<pair<int, int>> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i].first >> A[i].second;
    ans += A[i].second * n - A[i].first;
    A[i].first = A[i].first - A[i].second;
    A[i].second = 0;
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  for (int i = 0; i < n; i++) ans += (i + 1) * (A[i].first - A[i].second);
  cout << ans << '\n';
}
