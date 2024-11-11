#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
map<pair<int, int>, int> m;
bool comp(pair<int, int> p1, pair<int, int> p2) { return p1.first < p2.first; }
bool comp1(pair<int, int> p1, pair<int, int> p2) {
  return p1.second < p2.second;
}
int main() {
  int n, x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
    m[make_pair(x, y)]++;
  }
  sort(v.begin(), v.end(), comp);
  map<pair<int, int>, int>::iterator itr;
  long long sum = 0, count = 0;
  for (int i = 0; i < v.size(); i++) {
    if (i == 0 or v[i].first == v[i - 1].first) {
      count++;
    } else {
      sum += (count * (count - 1)) / 2;
      count = 1;
    }
  }
  sum += (count * (count - 1)) / 2;
  sort(v.begin(), v.end(), comp1);
  count = 0;
  for (int i = 0; i < v.size(); i++) {
    if (i == 0 or v[i].second == v[i - 1].second) {
      count++;
    } else {
      sum += (count * (count - 1)) / 2;
      count = 1;
    }
  }
  sum += (count * (count - 1)) / 2;
  for (itr = m.begin(); itr != m.end(); itr++) {
    long long val = itr->second;
    sum -= (val * (val - 1)) / 2;
  }
  cout << sum;
  return 0;
}
