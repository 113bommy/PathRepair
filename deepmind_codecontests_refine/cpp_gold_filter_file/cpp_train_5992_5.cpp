#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int> > d(n, pair<int, int>(0, 0));
  for (int i = 0; i < n; i++) {
    cin >> d[i].second;
    d[i].first = i + 1;
  }
  sort(d.begin(), d.end(), comp);
  for (int i = 0; i < n / 2; i++) {
    cout << d[i].first << " " << d[(n - i) - 1].first << endl;
  }
  return 0;
}
