#include <bits/stdc++.h>
using namespace std;
const int N = 256;
int n, a[N], b[N], c[N], d[N];
string s;
void setup(string &s) {
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
  memset(d, 0, sizeof(d));
  for (char k : s) a[k - '0']++, b[k - '0']++;
}
int get(string s, string t) {
  long long x = stoi(s);
  long long y = stoi(t);
  long long z = x + y;
  long long res = 0;
  while (!(z % 10)) res++, z /= 10;
  return res;
}
int brute(string s) {
  sort(s.begin(), s.end());
  int res = 0;
  string t = s;
  do {
    do {
      res = max(res, get(s, t));
    } while (next_permutation(s.begin(), s.end()));
  } while (next_permutation(t.begin(), t.end()));
  return res;
}
pair<string, string> solve(string &s) {
  vector<pair<int, int>> v;
  pair<int, int> en = {-1, -1};
  setup(s);
  for (int i = 0; i < 10; i++)
    while (a[i] && b[9 - i]) a[i]--, c[i]++, b[9 - i]--, d[9 - i]++;
  for (int i = 0; i < 10; i++)
    if (a[i] && b[10 - i]) en = {i, 10 - i};
  if (en.first < 0) {
    for (int i = 0; i < 10; i++)
      if (a[i] && d[10 - i]) en = {i, 10 - i};
    for (int i = 0; i < 10; i++)
      if (b[i] && c[10 - i]) en = {i, 10 - i};
  }
  if (en.first < 0) {
    for (int i = 0; i < 10; i++)
      if (c[i] && d[10 - i]) en = {i, 10 - i};
  }
  if (en.first < 0) {
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    return {s, s};
  }
  setup(s);
  vector<pair<int, int>> res;
  vector<pair<int, int>> zero;
  res.push_back({en.first, en.second});
  a[en.first]--;
  b[en.second]--;
  for (int i = 0; i < 10; i++)
    while (a[i] && b[9 - i]) a[i]--, b[9 - i]--, res.push_back({i, 9 - i});
  while (a[0] && b[0]) zero.push_back({0, 0}), a[0]--, b[0]--;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      while (a[i] && b[j]) res.push_back({i, j}), a[i]--, b[j]--;
  reverse(res.begin(), res.end());
  for (auto it : zero) res.push_back(it);
  string l = "", r = "";
  for (auto it : res) {
    l += ('0' + it.first);
    r += ('0' + it.second);
  }
  return {l, r};
}
bool check(string &s) {
  pair<string, string> res = solve(s);
  string l = res.first;
  string r = res.second;
  int xx = get(l, r);
  int yy = brute(s);
  if (xx != yy) {
    cout << "Fail at: " << s << endl;
    cout << "Expected " << yy << " got " << xx << " (" << l << "," << r << ")"
         << endl;
    return 0;
  }
  return 1;
}
bool BRUTE = 0;
int main() {
  ios::sync_with_stdio(false);
  if (BRUTE) {
    for (int i = 1; i < 10000; i++) {
      string s = to_string(i);
      check(s);
    }
  } else {
    cin >> s;
    pair<string, string> res = solve(s);
    cout << res.first << endl << res.second << endl;
  }
}
