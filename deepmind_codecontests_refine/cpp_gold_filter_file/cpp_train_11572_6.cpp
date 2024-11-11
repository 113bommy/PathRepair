#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string left;
  multimap<char, int> m;
  multimap<char, int>::iterator itr;
  cin >> left;
  string right;
  cin >> right;
  for (int i = 0; i < n; i++) {
    m.insert({right[i], i});
  }
  vector<vector<int> > v;
  vector<int> qm[1];
  for (int i = 0; i < n; i++) {
    if (left[i] == '?') {
      qm[0].push_back(i);
    } else {
      itr = m.find(left[i]);
      if (itr == m.end()) {
        itr = m.find('?');
        if (itr != m.end()) {
          vector<int> temp;
          temp.push_back(i + 1);
          temp.push_back(itr->second + 1);
          v.push_back(temp);
          m.erase(itr);
        }
      } else {
        vector<int> temp;
        temp.push_back(i + 1);
        temp.push_back(itr->second + 1);
        v.push_back(temp);
        m.erase(itr);
      }
    }
  }
  for (int i = 0; i < qm[0].size(); i++) {
    vector<int> temp;
    temp.push_back(qm[0][i] + 1);
    itr = m.begin();
    temp.push_back(itr->second + 1);
    v.push_back(temp);
    m.erase(itr);
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i][0] << " " << v[i][1] << endl;
  }
}
