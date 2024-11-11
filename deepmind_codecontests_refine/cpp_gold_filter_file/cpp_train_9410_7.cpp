#include <bits/stdc++.h>
using namespace std;
int dist[400];
int main() {
  string s;
  cin >> s;
  int n = s.length(), i, am = 0, pos, ch = 0;
  dist[n - 1] = -1;
  for (i = n - 2; i >= 0; i--) {
    if (s[i + 1] == '@' && s[i] == '@') {
      cout << "No solution" << endl;
      return 0;
    }
    if (s[i] == '@') {
      dist[i] = 0;
    } else {
      dist[i] = dist[i + 1] + (dist[i + 1] >= 0);
    }
  }
  if (dist[0] <= 0 || s[n - 1] == '@') {
    cout << "No solution" << endl;
    return 0;
  }
  pos = dist[0];
  while (pos < n + am - 1) {
    if (dist[pos] <= 0) {
      pos++;
      continue;
    }
    if (dist[pos] < 2) {
      cout << "No solution" << endl;
      return 0;
    }
    s.insert(s.begin() + pos + 1 + am, ',');
    am++;
    pos += dist[pos] + 1;
  }
  cout << s << endl;
}
