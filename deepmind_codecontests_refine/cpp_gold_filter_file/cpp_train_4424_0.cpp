#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int xChange[] = {0, 1, 0, -1};
int yChange[] = {1, 0, -1, 0};
string s, Target = "CODEFORCES";
int idx;
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    for (int j = i + 1; j <= (int)s.size(); j++) {
      string check = s.substr(0, i) + s.substr(j, (int)s.size());
      if (check == Target) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
