#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long m;
  cin >> m;
  vector<string> vec(m);
  for (long long i = 0; i < m; i++) {
    cin >> vec[i];
  }
  bool vis[26];
  for (long long i = 0; i < 26; i++) {
    vis[i] = false;
  }
  for (long long i = 0; i < n; i++) {
    if (s[i] != '*') {
      vis[s[i] - 'a'] = true;
    }
  }
  for (long long i = 0; i < vec.size(); i++) {
    for (long long j = 0; j < n; j++) {
      if (s[j] != '*') {
        if (s[j] != vec[i][j]) {
          vec.erase(vec.begin() + i);
          i--;
          break;
        }
      }
      if (s[j] == '*') {
        if (vis[vec[i][j] - 'a']) {
          vec.erase(vec.begin() + i);
          i--;
          break;
        }
      }
    }
  }
  vector<char> v;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '*') {
      if (vis[vec[0][i] - 'a'] == false) {
        v.push_back(vec[0][i]);
      }
    }
  }
  for (long long i = 1; i < vec.size(); i++) {
    for (long long k = 0; k < v.size(); k++) {
      bool t = false;
      for (long long j = 0; j < n; j++) {
        if (s[i] == '*' && v[k] == vec[i][j]) {
          t = true;
          break;
        }
      }
      if (!t) {
        v.erase(v.begin() + k);
        k--;
      }
    }
  }
  set<char> sec;
  for (long long i = 0; i < vec.size(); i++) {
    sec.insert(v[i]);
  }
  cout << sec.size() << endl;
  return 0;
}
