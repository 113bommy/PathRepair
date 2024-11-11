#include <bits/stdc++.h>
using namespace std;
vector<int> one[26], two[26];
vector<int> uone, utwo;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string left, right;
  cin >> left >> right;
  vector<int> q1, q2;
  for (int i = 0; i < left.size(); ++i) {
    if (left[i] == '?')
      q1.emplace_back(i);
    else
      one[left[i] - 'a'].push_back(i);
  }
  for (int i = 0; i < right.size(); ++i) {
    if (right[i] == '?')
      q2.emplace_back(i);
    else
      two[right[i] - 'a'].push_back(i);
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < 26; ++i) {
    while (one[i].size() && two[i].size()) {
      ans.emplace_back(one[i].back(), two[i].back());
      one[i].pop_back();
      two[i].pop_back();
    }
    while (one[i].size()) {
      uone.emplace_back(one[i].back());
      one[i].pop_back();
    }
    while (two[i].size()) {
      utwo.emplace_back(two[i].back());
      two[i].pop_back();
    }
  }
  while (uone.size() && q2.size()) {
    ans.emplace_back(uone.back(), q2.back());
    uone.pop_back();
    q2.pop_back();
  }
  while (utwo.size() && q1.size()) {
    ans.emplace_back(utwo.back(), q1.back());
    utwo.pop_back();
    q1.pop_back();
  }
  while (q1.size() && q2.size()) {
    ans.emplace_back(q1.back(), q2.back());
    q1.pop_back();
    q2.pop_back();
  }
  cout << ans.size() << "\n";
  for (auto a : ans) {
    cout << a.first + 1 << " " << a.second + 1 << "\n";
  }
}
