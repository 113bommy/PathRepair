#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, k, p;
  cin >> n >> k >> p;
  vector<int> odds, evens;
  vector<vector<int> > parts(k, vector<int>());
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    if (temp % 2)
      odds.push_back(temp);
    else
      evens.push_back(temp);
  }
  if ((int)odds.size() < k - p || ((int)odds.size() - k + p) % 2 ||
      ((int)odds.size() - k + p) / 2 + (int)evens.size() < p) {
    cout << "NO" << endl;
    return 0;
  } else
    cout << "YES" << endl;
  for (int i = 0; i < p; i++) {
    if (odds.size() > k - p) {
      parts[i].push_back(odds.back());
      odds.pop_back();
      parts[i].push_back(odds.back());
      odds.pop_back();
    } else {
      parts[i].push_back(evens.back());
      evens.pop_back();
    }
    while (i == p - 1 && !evens.empty()) {
      parts[i].push_back(evens.back());
      evens.pop_back();
    }
    while (i == p - 1 && odds.size() > k - p) {
      parts[i].push_back(odds.back());
      odds.pop_back();
      parts[i].push_back(odds.back());
      odds.pop_back();
    }
  }
  for (int i = p; i < k; i++) {
    parts[i].push_back(odds.back());
    odds.pop_back();
    while (i == k - 1 && !odds.empty()) {
      parts[i].push_back(odds.back());
      odds.pop_back();
    }
    while (i == p - 1 && !evens.empty()) {
      parts[i].push_back(evens.back());
      evens.pop_back();
    }
  }
  for (int i = 0; i < k; ++i) {
    cout << parts[i].size() << " ";
    for (int j = 0; j < parts[i].size(); j++) cout << parts[i][j] << " ";
    cout << endl;
  }
  return 0;
}
