#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int> > a;
int n, num = 1009;
bool comp(pair<pair<int, int>, int> c, pair<pair<int, int>, int> b) {
  if (c.first.first / num == b.first.first / num)
    return c.first.second < b.first.second;
  return c.first.first < b.first.first;
}
int main() {
  cin >> n;
  for (int i = 0, x, y; i < n; i++) {
    scanf("%d%d", &x, &y);
    a.push_back(make_pair(make_pair(x, y), i));
  }
  sort(a.begin(), a.end(), comp);
  for (int i = 0; i < (int)a.size(); i++) cout << a[i].second + 1 << " ";
  cout << endl;
  return 0;
}
