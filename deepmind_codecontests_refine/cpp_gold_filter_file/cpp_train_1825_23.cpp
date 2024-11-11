#include <bits/stdc++.h>
using namespace std;
vector<int> kmp(const vector<pair<long long, char> > &s) {
  int n = (int)s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
bool contains(pair<long long, char> a, pair<long long, char> b) {
  return (a.second == b.second && a.first >= b.first);
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<long long, char> > t, s;
  long long l, len;
  char c, prev;
  scanf("%lld-%c", &l, &c);
  len = l;
  prev = c;
  for (int i = 1; i < n; i++) {
    scanf("%lld-%c", &l, &c);
    if (prev != c) {
      t.emplace_back(len, prev);
      len = l;
      prev = c;
    } else
      len += l;
  }
  t.emplace_back(len, prev);
  scanf("%lld-%c", &l, &c);
  len = l;
  prev = c;
  for (int i = 1; i < m; i++) {
    scanf("%lld-%c", &l, &c);
    if (prev != c) {
      s.emplace_back(len, prev);
      len = l;
      prev = c;
    } else
      len += l;
  }
  s.emplace_back(len, prev);
  long long cnt = 0;
  if (s.size() == 1) {
    l = s.front().first;
    c = s.front().second;
    for (int i = 0; i < t.size(); i++) {
      if (t[i].second == c && t[i].first >= l) cnt += t[i].first - l + 1;
    }
    printf("%lld\n", cnt);
  } else {
    pair<long long, char> f = s.front(), b = s.back();
    s.erase(s.begin());
    s.pop_back();
    l = s.size();
    s.emplace_back(1, '$');
    s.insert(s.end(), t.begin(), t.end());
    vector<int> pi = kmp(s);
    for (int i = 2 * l + 1; i + 1 < s.size(); i++) {
      if (pi[i] == l && contains(s[i - l], f) && contains(s[i + 1], b)) cnt++;
    }
    printf("%lld\n", cnt);
  }
  return 0;
}
