#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int xChange[] = {0, 1, 0, -1};
int yChange[] = {1, 0, -1, 0};
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  string s, t;
  cin >> s >> t;
  int pos = 0, idx = 0;
  for (int i = 0; i < t.size(); i++) {
    if (i < s.size() && t[i] == s[idx]) pos++, idx++;
  }
  cout << pos + 1;
  return 0;
}
