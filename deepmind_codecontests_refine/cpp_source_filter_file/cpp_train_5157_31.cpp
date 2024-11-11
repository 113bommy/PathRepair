#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
pair<char, char> dirn(int i) {
  pair<char, char> c;
  if (v[i].first == v[i - 1].first) {
    if (v[i].second > v[i - 1].first)
      c.first = 'n';
    else
      c.first = 's';
  }
  if (v[i].second == v[i - 1].second) {
    if (v[i].first > v[i - 1].first)
      c.first = 'e';
    else
      c.first = 'w';
  }
  if (v[i].first == v[i + 1].first) {
    if (v[i].second > v[i + 1].second)
      c.second = 's';
    else
      c.second = 'n';
  }
  if (v[i].second == v[i + 1].second) {
    if (v[i].first > v[i + 1].first)
      c.second = 'w';
    else
      c.second = 'e';
  }
  return c;
}
int main() {
  int i, j, n, xx, yy, out = 0;
  cin >> n;
  pair<char, char> d;
  for (i = 0; i <= n; i++) {
    scanf("%d %d", &xx, &yy);
    v.push_back(make_pair(xx, yy));
  }
  for (i = 1; i < n; i++) {
    d = dirn(i);
    if (d.first == 's' && d.second == 'e')
      out++;
    else if (d.first == 'n' && d.second == 'w')
      out++;
    else if (d.first == 'e' && d.second == 'n')
      out++;
    else if (d.first == 'w' && d.second == 's')
      out++;
  }
  printf("%d\n", out);
}
