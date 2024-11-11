#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, char>> v;
int n;
int m;
vector<pair<long long int, char>> t;
char buf[200002];
pair<long long int, char> input() {
  long long int a;
  scanf("%I64d", &a);
  scanf("%s", buf);
  return make_pair(a, buf[1]);
}
vector<pair<long long int, char>> clean(vector<pair<long long int, char>> &vv) {
  vector<pair<long long int, char>> V;
  V.push_back(vv[0]);
  for (int i = 1; i < vv.size(); i++) {
    if (V.back().second == vv[i].second) {
      V.back().first += vv[i].first;
    } else {
      V.push_back(vv[i]);
    }
  }
  return V;
}
int linkk[200002];
deque<pair<long long int, char>> q;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    v.push_back(input());
  }
  for (int i = 0; i < m; i++) {
    t.push_back(input());
    if (i) {
      q.push_back(t.back());
    }
  }
  v = clean(v);
  t = clean(t);
  q.clear();
  for (int i = 1; i < t.size(); i++) {
    q.push_back(t[i]);
  }
  if (v.size() < t.size()) {
    puts("0");
    return 0;
  }
  if (t.size() == 1) {
    long long int ans = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].second == t[0].second) {
        if (v[i].first >= t[0].first) {
          ans += (long long int)(v[i].first - t[0].first + 1LL);
        }
      }
    }
    printf("%I64d\n", ans);
    return 0;
  }
  if (t.size() == 2) {
    long long int ans = 0;
    for (int i = 0; i + 1 < v.size(); i++) {
      if (v[i].second == t[0].second) {
        if (v[i].first >= t[0].first) {
          if (v[i + 1].second == t[1].second) {
            if (v[i + 1].first >= t[1].first) {
              ans++;
            }
          }
        }
      }
    }
    printf("%I64d\n", ans);
    return 0;
  }
  n = v.size();
  q.pop_back();
  m = q.size();
  {
    int i = 0;
    int j = -1;
    linkk[0] = -1;
    while (i < m) {
      while (j >= 0 && q[i] != q[j]) {
        j = linkk[j];
      }
      i++;
      j++;
      linkk[i] = j;
    }
  }
  long long int ans = 0;
  {
    int i = 0;
    int j = 0;
    while (i < n - 1) {
      while (j >= 0 && v[i] != q[j]) {
        j = linkk[j];
      }
      j++;
      if (j == m) {
        j = linkk[j];
        if (i - m >= 0 && v[i - m].second == t[0].second &&
            v[i - m].first >= t[0].first &&
            v[i + 1].second == t.back().second &&
            v[i + 1].first >= t.back().first) {
          ans++;
        }
      }
      i++;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
