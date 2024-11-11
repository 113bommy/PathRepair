#include <bits/stdc++.h>
using namespace std;
int n, x, y, d;
vector<vector<int> > dishes;
vector<long long int> m;
void SingleCase(int tcn) {
  cin >> n;
  vector<int> a(n, 0);
  vector<int> b(n, 0);
  for (int i = 0; i < int(n); i++) {
    cin >> a[i];
  }
  for (int i = 0; i < int(n); i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < int(n); i++) cout << a[i] << " ";
  cout << endl;
  for (int i = 0; i < int(n); i++) cout << b[i] << " ";
  cout << endl;
}
void MultiCases() {
  int tc;
  cin >> tc;
  for (int tcn = 0; tcn < int(tc); tcn++) {
    SingleCase(tcn);
  }
}
int calc(int b, int m) { return 2 * b - 2 * m + 1; }
int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> ans;
  ans.push_back(1);
  ans.push_back(2);
  int jiange = -1;
  for (int i = 0; i < int(n - 2); i++) {
    if (jiange > -1)
      ans.push_back(ans.back() + jiange);
    else {
      int j = ans.back() + 1;
      int maxh = floor((j - 1) / 2);
      if (m > maxh) {
        m -= maxh;
        ans.push_back(j);
      } else {
        ans.push_back(calc(ans.back(), m));
        jiange = ans.back() + 1;
        m = 0;
      }
    }
  }
  if (m > 0) {
    cout << -1;
  } else {
    for (int i = 0; i < int(n); i++) cout << i << " ";
  }
}
