#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int cnt;
    cin >> cnt;
    set<string> allStrings;
    vector<pair<string, int> > v01, v10;
    int cntDupZero = 0;
    int cntDupOne = 0;
    for (int i = 1; i <= cnt; i++) {
      string tmp;
      cin >> tmp;
      allStrings.insert(tmp);
      if (tmp[0] == '0' && tmp[tmp.size() - 1] == '0') {
        cntDupZero++;
      } else if (tmp[0] == '1' && tmp[tmp.size() - 1] == '1') {
        cntDupOne++;
      } else if (tmp[0] == '0' && tmp[tmp.size() - 1] == '1') {
        v01.push_back(make_pair(tmp, i));
      } else if (tmp[0] == '1' && tmp[tmp.size() - 1] == '0') {
        v10.push_back(make_pair(tmp, i));
      }
    }
    if (cntDupOne + cntDupZero > 0 && v01.size() + v10.size() == 0) {
      cout << "-1" << endl;
      continue;
    }
    vector<pair<string, int> > biggest, smallest;
    biggest = v01.size() > v10.size() ? v01 : v10;
    smallest = v01.size() < v10.size() ? v01 : v10;
    int totalChanges = (biggest.size() - smallest.size()) / 2;
    vector<int> solution;
    for (int i = 0; i < biggest.size() && totalChanges > 0; i++) {
      string tmp = biggest[i].first;
      reverse(tmp.begin(), tmp.end());
      if (allStrings.find(tmp) == allStrings.end()) {
        totalChanges--;
        solution.push_back(biggest[i].second);
      }
    }
    if (totalChanges == 0) {
      cout << (biggest.size() - smallest.size()) / 2 << endl;
      for (int i : solution) {
        cout << i << " ";
      }
      cout << endl;
    } else {
      cout << "-1" << endl;
    }
  }
}
