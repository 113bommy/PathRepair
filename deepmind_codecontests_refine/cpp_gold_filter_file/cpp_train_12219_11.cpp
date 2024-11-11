#include <bits/stdc++.h>
using namespace std;
bool comp(pair<string, int> p1, pair<string, int> p2) {
  return p1.second > p2.second;
}
int main() {
  int n;
  cin >> n;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i % 3 == 0)
      mp["chest"] += x;
    else if (i % 3 == 1)
      mp["biceps"] += x;
    else
      mp["back"] += x;
  }
  vector<pair<string, int> > v(mp.begin(), mp.end());
  sort(v.begin(), v.end(), comp);
  cout << (*v.begin()).first;
}
