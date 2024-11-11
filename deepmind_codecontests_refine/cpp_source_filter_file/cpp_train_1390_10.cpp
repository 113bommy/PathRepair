#include <bits/stdc++.h>
using namespace std;
struct abc {
  string s;
  int x, y, z;
};
bool operator<(abc l, abc r) {
  if ((l.x < r.x) || ((l.x == r.x) && (l.y < r.y)) ||
      ((l.x == r.x) && (l.y == r.y) && (l.z < r.z)))
    return true;
  else
    return false;
}
int n, i, j, x1, x2;
string s, s1, s2;
map<string, int> m1, m2, m3;
map<string, int>::iterator it;
vector<abc> v;
vector<string> v0;
int main() {
  cin >> n;
  for (i = 0; i <= n; i++) getline(cin, s);
  for (i = 1; i <= n * (n - 1) / 2; i++) {
    getline(cin, s);
    j = 0;
    s1 = "";
    s2 = "";
    x1 = 0;
    x2 = 0;
    while (s[j] != '-') {
      s1 = s1 + s[j];
      j++;
    }
    j++;
    while (s[j] != ' ') {
      s2 = s2 + s[j];
      j++;
    }
    j++;
    while (s[j] != ':') {
      x1 = x1 * 10 + char(s[j]) - '0';
      j++;
    }
    j++;
    while (j < s.size()) {
      x2 = x2 * 10 + char(s[j]) - '0';
      j++;
    }
    if (x1 == x2) {
      m1[s1]++;
      m1[s2]++;
    }
    if (x1 > x2) m1[s1] += 3;
    if (x1 < x2) m1[s2] += 3;
    m1[s1] += x1;
    m1[s2] += x2;
    m2[s1] += x2;
    m2[s2] += x1;
  }
  for (it = m1.begin(); it != m1.end(); it++) {
    abc c;
    c.s = (*it).first;
    c.x = m1[c.s];
    c.y = m2[c.s] - m3[c.s];
    c.z = m2[c.s];
    v.push_back(c);
  }
  sort(v.rbegin(), v.rend());
  for (i = 0; i < n / 2; i++) v0.push_back(v[i].s);
  sort(v0.begin(), v0.end());
  for (i = 0; i < n / 2; i++) cout << v0[i] << endl;
  return 0;
}
