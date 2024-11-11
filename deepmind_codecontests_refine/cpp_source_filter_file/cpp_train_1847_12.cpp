#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, pair<int, int> > > v;
bool cmp(pair<long long, pair<int, int> > &a,
         pair<long long, pair<int, int> > &b) {
  return a.first < b.first;
}
int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    vector<int> x;
    int n;
    cin >> n;
    x.clear();
    x.resize(n + 5);
    long long int s = 0;
    for (int j = 0; j < n; j++) {
      cin >> x[j];
      s += x[j];
    }
    for (int j = 0; j < n; j++)
      v.push_back(make_pair(s - x[j], make_pair(i + 1, j + 1)));
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 1; i < v.size(); i++) {
    if (v[i].first == v[i - 1].first &&
        v[i].second.first != v[i - 1].second.first) {
      cout << "YES\n";
      cout << v[i].second.first << " " << v[i].second.second << "\n";
      cout << v[i - 1].second.first << " " << v[i].second.second << "\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
