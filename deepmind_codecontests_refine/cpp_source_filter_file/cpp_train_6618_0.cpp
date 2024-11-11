#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
double pi = 3.1415926535898;
const long long M = 1e9 + 7;
const int N = 50500;
const int inf = INT_MAX;
const double eps = 1e-6;
map<string, int> mp1;
map<int, vector<string>> mp2;
set<string> st;
int point[300];
int main() {
  string name, s, s1, s2, s3, s4;
  point['P'] = 15;
  point['c'] = 10;
  point['l'] = 5;
  int n;
  cin >> name;
  cin >> n;
  for (int i = 0; i < int(n); i++) {
    cin >> s1 >> s2;
    if (s2[0] != 'l') cin >> s4;
    cin >> s3;
    s3.pop_back();
    s3.pop_back();
    cin >> s4;
    if (s1 == name)
      mp1[s3] += point[s2[0]];
    else if (s3 == name)
      mp1[s1] += point[s2[0]];
    else {
      st.insert(s1);
      st.insert(s3);
    }
  }
  for (auto x : mp1) {
    mp2[-x.second].push_back(x.first);
  }
  for (auto x : mp2) {
    for (auto y : x.second) {
      cout << y << endl;
      st.erase(y);
    }
  }
  for (auto x : st) {
    cout << x << endl;
  }
  return 0;
  ;
}
