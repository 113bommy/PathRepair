#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int size(const T &c) {
  return c.size();
}
vector<pair<long long, int> > data;
char s[64];
int n, m;
void doit(long long mask, int depth, int max_depth, int match, long long curr,
          vector<long long> &answer) {
  if (match < 0) return;
  if (depth == max_depth) {
    if (match == 0) answer.push_back(curr);
    return;
  }
  long long v = (mask & ((long long)1 << (depth)));
  doit(mask, depth + 1, max_depth, match - (v == 0), curr, answer);
  doit(mask, depth + 1, max_depth, match - (v != 0),
       curr | ((long long)1 << (depth)), answer);
}
int solve() {
  set<long long> ret;
  bool first = true;
  for (__typeof(data.begin()) it = data.begin(); it != data.end(); ++it) {
    vector<long long> answer;
    doit(it->first, 0, n, it->second, 0, answer);
    if (first) {
      for (__typeof(answer.begin()) x = answer.begin(); x != answer.end(); ++x)
        ret.insert(*x);
    } else {
      set<long long> ret2;
      for (__typeof(answer.begin()) x = answer.begin(); x != answer.end(); ++x)
        if (ret.find(*x) != ret.end()) ret2.insert(*x);
      ret = ret2;
    }
    first = false;
  }
  return size(ret);
}
int brutal() {
  int ans = 0;
  for (int mask = 0, _n = (1 << n); mask < _n; ++mask) {
    bool ok = true;
    for (__typeof(data.begin()) it = data.begin(); it != data.end(); ++it) {
      long long mask2 = it->first;
      int match = 0;
      for (int i = 0, _n = (n); i < _n; ++i) {
        int va = mask & (1 << i);
        int vb = mask2 & (1 << i);
        match += va == vb;
      }
      if (match != it->second) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans++;
    }
  }
  return ans;
}
int main() {
  while (scanf("%d %d", &n, &m) == 2) {
    data.clear();
    data.resize(m);
    for (int i = 0, _n = (m); i < _n; ++i) {
      scanf("%s %d", s, &data[i].second);
      data[i].first = 0;
      for (int j = (strlen(s) - 1), _b = (0); j >= _b; --j)
        data[i].first = data[i].first * 2 + s[j] - '0';
    }
    cout << solve() << endl;
  }
  return 0;
}
