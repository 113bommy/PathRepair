#include <bits/stdc++.h>
using namespace std;
double sqr(double first) { return first * first; }
const long long md = 1e9 + 7;
const long long md2 = 2e9 + 7;
const double PI = acos(-1);
const int MAXN = 2e6 + 1;
const int INF = 1e9 + 1;
const int RNG = 1e8 + 10;
const pair<int, int> turns[4] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
const char signs[4] = {'D', 'L', 'R', 'U'};
string s;
char a[2000][2000];
int main() {
  ios::sync_with_stdio(false);
  cin >> s >> s;
  int maxDepth = 0, depth = 0;
  for (auto c : s) {
    if (c == '[')
      depth++;
    else
      depth--;
    maxDepth = max(maxDepth, depth);
  }
  int n = int((s).size()), m = 2 * maxDepth + 1;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      a[i][j] = ' ';
    }
  }
  int first = 0, second = maxDepth;
  for (int j = 0; j < int((s).size()); j++) {
    char c = s[j];
    for (int i = 0; i < maxDepth; i++) {
      a[first][second + i] = a[first][second - i] = '|';
    }
    a[first][second - maxDepth] = a[first][second + maxDepth] = '+';
    if (c == '[') {
      a[first + 1][second - maxDepth] = a[first + 1][second + maxDepth] = '-';
    } else {
      a[first - 1][second - maxDepth] = a[first - 1][second + maxDepth] = '-';
    }
    if (j + 1 != int((s).size())) {
      first++;
      if (s[j] == '[' && s[j + 1] == '[') {
        maxDepth--;
      } else if (s[j] == ']' && s[j + 1] == ']') {
        maxDepth++;
      } else if (s[j] == '[' && s[j + 1] == ']') {
        first += 3;
      }
    }
  }
  for (int j = 0; j < m; j++) {
    vector<char> v;
    for (int i = 0; i <= first; i++) {
      v.push_back(a[i][j]);
    }
    while (v.back() == ' ') v.pop_back();
    for (auto c : v) cout << c;
    cout << "\n";
  }
}
