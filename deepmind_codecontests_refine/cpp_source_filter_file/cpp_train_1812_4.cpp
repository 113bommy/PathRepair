#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<string> A;
vector<pair<int, pair<int, int> > > R;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    A.push_back(s);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (A[i][j] == '*') {
        for (int l = 0; l < max(n, m) + 1; l++) {
          if (i - l < 0 || j - l < 0 || i + l >= n || j + l >= m) break;
          if (A[i - l][j] == '*' && A[i + l][j] == '*' && A[i][j - l] == '*' &&
              A[i][j + l] == '*')
            R.push_back(make_pair(l, make_pair(i, j)));
        }
      }
  sort(R.begin(), R.end());
  if (R.size() < k)
    cout << -1 << endl;
  else {
    k--;
    int l = R[k].first, x = R[k].second.first + 1, y = R[k].second.second + 1;
    cout << x << ' ' << y << endl;
    cout << x - l << ' ' << y << endl;
    cout << x + l << ' ' << y << endl;
    cout << x << ' ' << y - l << endl;
    cout << x << ' ' << y + l << endl;
  }
  cin >> n;
  return 0;
}
