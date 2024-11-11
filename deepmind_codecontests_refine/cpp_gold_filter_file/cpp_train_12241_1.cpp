#include <bits/stdc++.h>
using namespace std;
void solutionD();
int main() {
  ios_base::sync_with_stdio(false);
  solutionD();
  return EXIT_SUCCESS;
}
long long n;
string s;
char c1(long long i, long long depth, long long max_depth) {
  if (max_depth - depth == i || max_depth + depth == i)
    return '+';
  else if (max_depth - depth < i && max_depth + depth > i)
    return '|';
  else
    return ' ';
}
char c2(long long i, long long depth, long long max_depth) {
  if (max_depth - depth == i || max_depth + depth == i)
    return '-';
  else
    return ' ';
}
vector<string> f(const string& t, long long depth, long long max_depth) {
  vector<string> r(max_depth * 2 + 1);
  for (long long i = 0; i < max_depth * 2 + 1; ++i)
    r[i] += c1(i, depth, max_depth);
  if (t.size() == 2) {
    for (long long i = 0; i < max_depth * 2 + 1; ++i) r[i] += "   ";
  }
  string group;
  for (long long i = 1, n = t.size(), balance = 0; i < n - 1; ++i) {
    group += t[i];
    if (t[i] == '[')
      ++balance;
    else if (t[i] == ']')
      --balance;
    if (balance == 0) {
      vector<string> v = f(group, depth - 1, max_depth);
      group.clear();
      for (long long i = 0; i < max_depth * 2 + 1; ++i) r[i] += v[i];
    }
  }
  long long len = r[0].size();
  for (long long i = 0; i < max_depth * 2 + 1; ++i) {
    if (r[i][1] == ' ') r[i][1] = c2(i, depth, max_depth);
    if (r[i][len - 1] == ' ') r[i][len - 1] = c2(i, depth, max_depth);
  }
  for (long long i = 0; i < max_depth * 2 + 1; ++i)
    r[i] += c1(i, depth, max_depth);
  return r;
}
void solve() {
  long long depth = 0, max_depth = 0;
  vector<string> groups;
  string group;
  for (long long i = 0; i < n; ++i) {
    group += s[i];
    if (s[i] == '[')
      ++depth;
    else if (s[i] == ']')
      --depth;
    max_depth = max(max_depth, depth);
    if (depth == 0) {
      groups.push_back(group);
      group.clear();
    }
  }
  vector<string> r(max_depth * 2 + 1);
  for (string group : groups) {
    vector<string> v = f(group, max_depth, max_depth);
    for (long long i = 0; i < max_depth * 2 + 1; ++i) r[i] += v[i];
  }
  for (string l : r) cout << l << '\n';
}
void solutionD() {
  for (; cin >> n >> s;) {
    solve();
    cerr << endl;
  }
}
