#include <bits/stdc++.h>
using namespace std;
const int inf = 1999999999;
const double pi = acos(-1.0);
const double eps = 1e-10;
char gc() {
  char c;
  while (isspace(c = getchar()))
    ;
  return c;
}
int gs(char* s) {
  gets(s);
  int l = strlen(s);
  while (l && isspace(s[l - 1])) s[--l] = 0;
  return l;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<pair<int, int>, int> > v;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back(make_pair(make_pair(a, b), c));
  }
  long long s2 = 0;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    long long s = 0;
    for (int j = 0; j < ((int)(v).size()); j++) {
      if (v[j].first.first <= x && x <= v[j].first.second)
        s += v[j].second + x - v[j].first.first;
    }
    s2 += s;
  }
  cout << s2;
}
