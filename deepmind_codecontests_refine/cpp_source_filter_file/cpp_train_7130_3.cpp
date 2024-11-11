#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::multiset;
using std::pair;
using std::queue;
using std::set;
using std::sort;
using std::stack;
using std::string;
using std::to_string;
using std::vector;
int main() {
  int n;
  cin >> n;
  string bad[] = {"ABSINTH", "BEER",    "BRANDY", "CHAMPAGNE", "GIN", "RUM",
                  "SAKE",    "TEQUILA", "VODKA",  "WHISKEY",   "WINE"};
  int answer = 0;
  string s;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s[0] >= '0' && s[0] <= '9') {
      x = 0;
      for (int j = 0; j < s.size(); j++) {
        x *= 10;
        x += (s[j] - '0');
      }
      if (x < 18) answer++;
      continue;
    }
    int flag = 1;
    for (int j = 0; j < 11; j++) {
      if (bad[j] == s) flag = 0;
    }
    if (flag) answer++;
  }
  cout << answer;
  return 0;
}
