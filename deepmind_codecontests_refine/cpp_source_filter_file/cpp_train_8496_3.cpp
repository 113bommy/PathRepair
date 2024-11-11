#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<pair<int, int> > A(N);
  for (int i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
  int ans = 1;
  for (int i = 0; i < N; i++) {
    if (ans < A[i].first)
      ans = A[i].first;
    else {
      int x = (ans - A[i].first) / A[i].second;
      while (A[i].first + x * A[i].second <= ans) x++;
      ans = A[i].first + x * A[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}
