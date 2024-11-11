#include <bits/stdc++.h>
using namespace std;
long long gr[1013][1013];
int main() {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i < k; i++) {
    vector<int> post;
    vector<int> pos0;
    vector<int> pos1;
    for (int j = i; j < n; j += k) {
      if (s[j] == '.') {
        post.push_back(j);
      }
      if (s[j] == '0') {
        pos0.push_back(j);
      }
      if (s[j] == '0') {
        pos1.push_back(j);
      }
    }
    if (pos0.size() > 0 && pos1.size() > 0) {
      for (int u = 0; u < n; u++) {
        if (s[u] == '.') {
          cout << 1;
        } else
          cout << s[u];
      }
      return 0;
    }
    if (post.size() > 1) {
      s[post[0]] = '1';
      s[post[1]] = '0';
      for (int u = 0; u < n; u++) {
        if (s[u] == '.') {
          cout << 1;
        } else
          cout << s[u];
      }
      return 0;
    }
    if (post.size() > 0 && pos1.size() > 0) {
      s[post[0]] = '0';
      for (int u = 0; u < n; u++) {
        if (s[u] == '.') {
          cout << 1;
        } else
          cout << s[u];
      }
      return 0;
    }
    if (post.size() > 0 && pos0.size() > 0) {
      s[post[0]] = '1';
      for (int u = 0; u < n; u++) {
        if (s[u] == '.') {
          cout << 1;
        } else
          cout << s[u];
      }
      return 0;
    }
  }
  cout << "No";
  return 0;
}
