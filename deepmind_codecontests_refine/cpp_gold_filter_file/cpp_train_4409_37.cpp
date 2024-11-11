#include <bits/stdc++.h>
using namespace std;
int getOddOccurrence(vector<int> v) {
  unordered_map<int, int> hash;
  for (auto i = v.begin(); i != v.end(); ++i) {
    hash[*i]++;
  }
  for (auto i : hash) {
    if (i.second % 2 != 0) {
      return i.first;
    }
  }
  return -1;
}
int main() {
  int r, c;
  cin >> r >> c;
  string city[r];
  vector<int> v1, v2;
  for (int i = 0; i < r; i++) {
    cin >> city[i];
    for (int j = 0; j < c; j++) {
      if (city[i][j] == '*') {
        v1.push_back(i);
        v2.push_back(j);
      }
    }
  }
  cout << getOddOccurrence(v1) + 1 << " " << getOddOccurrence(v2) + 1;
  return 0;
}
