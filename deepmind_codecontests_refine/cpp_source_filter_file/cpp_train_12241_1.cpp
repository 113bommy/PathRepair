#include <bits/stdc++.h>
using namespace std;
int n, depth, pos[111];
char out[5000][5000];
string s, ans;
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '[') {
      pos[i] = ++depth;
    } else {
      pos[i] = depth--;
    }
  }
  depth = 0;
  int curr = 0;
  int h = *max_element(pos, pos + n);
  for (int i = 0; i < n; ++i, ++curr) {
    if (i && s[i] == ']' && s[i - 1] == '[') {
      curr += 3;
    }
    int width = 2 * (h - pos[i]) + 1;
    depth = max(depth, pos[i] + width);
    if (s[i] == '[') {
      out[pos[i] - 1][curr + 1] = '-';
      out[pos[i] + width][curr + 1] = '-';
    } else {
      out[pos[i] - 1][curr - 1] = '-';
      out[pos[i] + width][curr - 1] = '-';
    }
    out[pos[i] - 1][curr] = out[pos[i] + width][curr] = '+';
    for (int j = pos[i]; j < pos[i] + width; ++j) {
      out[j][curr] = '|';
    }
  }
  for (int i = 0; i <= depth; ++i) {
    ans.clear();
    for (int j = 0; j <= curr; ++j) {
      ans += out[i][j] ? out[i][j] : ' ';
    }
    cout << ans << "\n";
  }
  return 0;
}
