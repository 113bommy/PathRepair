#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1 || m == 1)
    cout << n * m << endl;
  else
    cout << n * m - 1 << endl;
  vector<pair<int, int> > pairs;
  for (int i = 1; i <= m; i++) pairs.push_back(make_pair(1, i));
  for (int i = 2; i <= n; i++) pairs.push_back(make_pair(i, 1));
  sort(pairs.begin(), pairs.end());
  for (int i = 0; i < pairs.size(); i++)
    cout << pairs[i].first << " " << pairs[i].second << endl;
  return 0;
}
