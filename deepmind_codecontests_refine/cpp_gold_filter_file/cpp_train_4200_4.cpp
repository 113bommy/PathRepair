#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> A(n), B(m);
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < m; i++) cin >> B[i];
  vector<pair<int, int> > C;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (A[i] - x <= B[j] && A[i] + y >= B[j])
      C.push_back(make_pair(++i, ++j));
    else if (B[j] < A[i])
      j++;
    else
      i++;
  }
  cout << C.size() << endl;
  for (int i = 0; i < C.size(); i++)
    cout << C[i].first << ' ' << C[i].second << endl;
  return 0;
}
