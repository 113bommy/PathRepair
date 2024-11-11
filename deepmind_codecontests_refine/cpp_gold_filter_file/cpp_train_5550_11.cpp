#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
vector<int> t[2];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    v.push_back(make_pair(k, i + 1));
  }
  sort(v.rbegin(), v.rend());
  int s[2];
  s[0] = 0;
  s[1] = 0;
  int c = 0;
  int i = 0;
  for (; i < n / 4; i++) {
    int k = 4 * i;
    s[0] += v[k].first + v[k + 3].first;
    s[1] += v[k + 1].first + v[k + 2].first;
    t[0].push_back(v[k].second);
    t[0].push_back(v[k + 3].second);
    t[1].push_back(v[k + 1].second);
    t[1].push_back(v[k + 2].second);
  }
  int minId = 0;
  if (s[0] <= s[1])
    minId = 0;
  else
    minId = 1;
  pair<int, int> m3 = 4 * i < n ? v[4 * i] : make_pair(0, -1),
                 m2 = 4 * i + 1 < n ? v[4 * i + 1] : make_pair(0, -1),
                 m1 = 4 * i + 2 < n ? v[4 * i + 2] : make_pair(0, -1);
  if (m1.first != 0 && m2.first != 0 && m3.first != 0)
    if (m1.first + m2.first >= m3.first) {
      t[minId].push_back(m1.second);
      t[minId].push_back(m2.second);
      t[(minId + 1) % 2].push_back(m3.second);
    } else {
      t[minId].push_back(m3.second);
      t[(minId + 1) % 2].push_back(m2.second);
      t[(minId + 1) % 2].push_back(m1.second);
    }
  else if (m3.first != 0 && m2.first != 0) {
    t[minId].push_back(m3.second);
    t[(minId + 1) % 2].push_back(m2.second);
  } else if (m3.first != 0) {
    t[minId].push_back(m3.second);
  }
  cout << t[0].size() << endl;
  for (int i = 0; i < t[0].size(); i++) cout << t[0][i] << " ";
  cout << endl << t[1].size() << endl;
  for (int i = 0; i < t[1].size(); i++) cout << t[1][i] << " ";
  return 0;
}
