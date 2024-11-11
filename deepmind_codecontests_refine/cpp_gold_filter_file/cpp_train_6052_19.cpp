#include <bits/stdc++.h>
using namespace std;
int arr[5][5];
int main() {
  string s;
  cin >> s;
  vector<pair<int, int>> vec1, vec2;
  int sz = s.size();
  vec1.push_back({1, 1});
  vec1.push_back({3, 1});
  vec2.push_back({1, 2});
  vec2.push_back({2, 2});
  vec2.push_back({3, 2});
  vec2.push_back({4, 2});
  int cn1 = 0, cn2 = 0;
  for (int i = 0; i < sz; i++) {
    if (s[i] == '0') {
      cout << vec1[cn1 % 2].first << " " << vec1[cn1 % 2].second << endl;
      cn1++;
    }
    if (s[i] == '1') {
      cout << vec2[cn2 % 4].first << " " << vec2[cn2 % 2].second << endl;
      cn2++;
    }
  }
}
