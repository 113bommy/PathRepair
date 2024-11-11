#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
using namespace std;
vector<vector<char> > picture;
void print(vector<vector<char> > a) {
  int n = a.size(), m = a[0].size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) printf("%c", a[i][j]);
    printf("\n");
  }
}
void testing(vector<vector<char> > a) {
  print(a);
  printf("\n\n\n");
}
vector<vector<char> > scan() {
  int n, m;
  scanf("%d%d", &m, &n);
  vector<vector<char> > a(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) a[i][j] = s[j];
  }
  return a;
}
vector<vector<char> > turn(vector<vector<char> > a) {
  int n = a.size(), m = a[0].size();
  vector<vector<char> > fresh(m, vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) fresh[j][n - i - 1] = a[i][j];
  }
  return fresh;
}
vector<vector<char> > turn_270(vector<vector<char> > a) {
  return turn(turn(turn(a)));
}
vector<char> get_double(vector<char> a) {
  vector<char> b;
  for (int i = 0; i < a.size(); ++i) b.push_back(a[i]), b.push_back(a[i]);
  return b;
}
vector<vector<char> > doubler(vector<vector<char> > a) {
  vector<vector<char> > fresh;
  int n = a.size(), m = a[0].size();
  for (int i = 0; i < n; ++i)
    fresh.push_back(get_double(a[i])), fresh.push_back(get_double(a[i]));
  return fresh;
}
vector<vector<char> > sim(vector<vector<char> > a) {
  vector<vector<char> > fresh = a;
  int n = a.size(), m = a[0].size();
  for (int i = 0; i < n; ++i) fresh[n - i - 1] = a[i];
  return fresh;
}
int main() {
  print(doubler(sim(turn_270(scan()))));
  return 0;
}
