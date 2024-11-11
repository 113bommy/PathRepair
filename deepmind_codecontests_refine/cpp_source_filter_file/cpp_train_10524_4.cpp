#include <bits/stdc++.h>
using namespace std;
int cnt[1000];
bool comp(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first != b.first)
    return a.first > b.first;
  else
    return a.second > b.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a, b, c, d;
  vector<pair<int, int> > v;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b >> c >> d;
    int sum = a + b + c + d;
    v.push_back(make_pair(sum, i));
    cnt[sum]++;
  }
  sort(v.begin(), v.end(), comp);
  for (int i = 0; i < n; i++) {
    if (v[i].second == 1) {
      cout << i + 1;
      return 0;
    }
  }
}
