#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int distance(pair<int, int> a, pair<int, int> b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}
int findpair(vector<pair<int, int>> v1, vector<pair<int, int>> v2) {
  for (pair<int, int> p : v1) {
    for (pair<int, int> q : v2) {
      if (distance(p, q) <= x * x) {
        return 1;
      }
    }
  }
  return -1;
}
int compute(unordered_map<int, vector<pair<int, int>>> umap,
            vector<pair<int, int>> shifts, char c) {
  if (umap.find(c + 32) == umap.end() || shifts.size() == 0) {
    return -1;
  }
  return (findpair(umap[c + 32], shifts) < 0);
}
int main() {
  cin >> n >> m >> x;
  unordered_map<int, vector<pair<int, int>>> umap;
  vector<pair<int, int>> shifts;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c != 'S')
        umap[c].push_back({i + 1, j + 1});
      else
        shifts.push_back({i + 1, j + 1});
    }
  }
  int N;
  cin >> N;
  string str;
  string cache = "ABCDEFGHIJKLMNOPQRSTUZWXYZ";
  int arr[26];
  cin >> str;
  for (char c : cache) {
    arr[c - 'A'] = compute(umap, shifts, c);
  }
  int sum = 0;
  for (char c : str) {
    if (c >= 'a' && c <= 'z') {
      if (umap.find(c) == umap.end()) {
        cout << -1 << endl;
        return 0;
      } else
        continue;
    }
    if (arr[c - 'A'] == -1) {
      cout << -1 << endl;
      return 0;
    }
    sum += arr[c - 'A'];
  }
  cout << sum << endl;
}
