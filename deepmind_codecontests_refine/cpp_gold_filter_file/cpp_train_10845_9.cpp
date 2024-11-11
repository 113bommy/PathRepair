#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.first + a.second > b.first + b.second;
}
int main(int argc, char const *argv[]) {
  int n, cs;
  vector<pair<int, int> > pos, neg;
  cin >> n >> cs;
  for (int i = 0; i < n; ++i) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    p.first = max(p.first, -p.second);
    if (p.second >= 0)
      pos.push_back(p);
    else
      neg.push_back(p);
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end(), cmp);
  for (int i = 0; i < pos.size(); ++i) {
    if (cs >= pos[i].first)
      cs += pos[i].second;
    else
      return cout << "No", 0;
  }
  for (int i = 0; i < neg.size(); ++i) {
    if (cs >= neg[i].first)
      cs += neg[i].second;
    else
      return cout << "No", 0;
  }
  cout << "Yes";
  return 0;
}
