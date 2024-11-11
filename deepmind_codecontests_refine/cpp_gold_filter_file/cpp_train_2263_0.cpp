#include <bits/stdc++.h>
using namespace std;
int next() {
  int x;
  cin >> x;
  return x;
}
long long lnext() {
  long long x;
  cin >> x;
  return x;
}
int main() {
  cout.precision(20);
  ios_base::sync_with_stdio(false);
  int n = next();
  vector<int> a;
  vector<vector<int>> pos(n);
  for (int i = 0; i < 2 * n; i++) {
    int x = next() - 1;
    a.push_back(x);
    pos[x].push_back(i);
  }
  int sum = 0;
  for (int i = 0; i < n; i++) sum += pos[i][1] - pos[i][0] - 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (pos[j][0] < pos[i][0] && pos[j][1] > pos[i][1]) sum += 2;
  }
  cout << sum / 2;
}
