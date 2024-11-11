#include <bits/stdc++.h>
using namespace std;
set<pair<string, int>> v;
string ar[1000];
string b = "";
bool ba(int i) {
  if (i == 0) return 1;
  bool r = false;
  string s = ar[i];
  s += ar[i - 1];
  if (i > 1) {
    s += ar[i - 2];
  }
  if (v.count({s, i})) return 0;
  v.insert({s, i});
  if ((ar[i][0] == ar[i - 1][0]) || (ar[i][1] == ar[i - 1][1])) {
    string t = ar[i - 1];
    ar[i - 1] = ar[i];
    r |= ba(i - 1);
    ar[i - 1] = t;
    if (r) return 1;
  }
  if (i > 2) {
    if ((i > 1) && ((ar[i][0] == ar[i - 3][0]) || (ar[i][1] == ar[i - 3][1]))) {
      string t = ar[i - 3];
      ar[i - 3] = ar[i];
      r |= ba(i - 1);
      ar[i - 3] = t;
      if (r) return 1;
    }
  }
  return 0;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> ar[i];
  }
  if (ba(n - 1))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
