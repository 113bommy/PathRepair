#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, num, sum = 0, count = 0;
  cin >> n >> m;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> num;
    v.push_back(make_pair(num, i + 1));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    sum = sum + v[i].first;
    if (sum < m)
      count++;
    else
      break;
  }
  cout << count;
  cout << endl;
  for (int i = 0; i < count; i++) {
    cout << v[i].second << " ";
  }
  return 0;
}
