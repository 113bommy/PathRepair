#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  stack<char> s;
  int count = 0, verticals = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '.') count++;
    if (str[i] == 'L') {
      if (!s.empty() and s.top() == 'R') {
        if (count % 2 == 1) {
          verticals++;
        }
      }
      count = 0;
      s.push(str[i]);
    }
    if (str[i] == 'R') {
      verticals += count;
      count = 0;
      s.push(str[i]);
    }
  }
  if (s.size() == 1) {
    if (str[0] == 'R' || (str[n - 1] == 'L')) {
      count = 0;
    }
  }
  if (s.empty() || s.top() == 'L') verticals += count;
  cout << verticals << "\n";
}
