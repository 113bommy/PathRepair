#include <bits/stdc++.h>
using namespace std;
const int MAX_M = 100000;
long long N, M;
vector<long long> vt;
map<long long, int> num;
vector<long long> v[MAX_M + 1];
int k = 0;
set<pair<long long, long long> > line;
vector<pair<long long, long long> > line2;
void move(long long x, long long y) {
  for (set<pair<long long, long long> >::iterator it = line.begin();
       it != line.end();) {
    set<pair<long long, long long> >::iterator it2 = it;
    it++;
    pair<long long, long long> p = *it2;
    line.erase(it2);
    if (p.first == x - 1) {
      p.first = min(N, p.first + (y - x));
    }
    if (p.second == 1) {
      p.second = max((long long)1, y - N);
    } else
      p.second += (y - x);
    if (p.second > p.first) continue;
    line2.push_back(p);
  }
  while (!line2.empty()) {
    line.insert(line2.back());
    line2.pop_back();
  }
}
void add(long long x) {
  if (line.empty()) {
    line.insert({x, x});
    return;
  }
  pair<long long, long long> p = {x, 0};
  set<pair<long long, long long> >::iterator it = line.lower_bound(p);
  if (it == line.end()) {
    it--;
    pair<long long, long long> t = *it;
    if (t.first == x - 1) {
      line.erase(t);
      line.insert({t.first + 1, t.second});
    } else {
      line.insert({x, x});
    }
  } else {
    pair<long long, long long> t = *it;
    if (x >= t.second) return;
    if (it == line.begin()) {
      if (x == t.second - 1) {
        line.erase(t);
        line.insert({t.first, t.second - 1});
      } else {
        line.insert({x, x});
      }
    } else {
      it--;
      pair<long long, long long> k = *it;
      if (x == t.second - 1) {
        if (x == k.first + 1) {
          line.erase(k);
          line.erase(t);
          line.insert({t.first, k.second});
        } else {
          line.erase(t);
          line.insert({t.first, t.second - 1});
        }
      } else {
        if (x == k.first + 1) {
          line.erase(k);
          line.insert({k.first + 1, k.second});
        } else {
          line.insert({x, x});
        }
      }
    }
  }
}
int main() {
  scanf("%lld%lld", &N, &M);
  for (int i = 0; i < M; i++) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    if (num[a + b] == 0) {
      num[a + b] = ++k;
    }
    v[num[a + b]].push_back(a);
    vt.push_back(a + b);
  }
  long long prv = 2;
  sort(vt.begin(), vt.end());
  vt.erase(unique(vt.begin(), vt.end()), vt.end());
  for (int i = 0; i < vt.size(); i++) {
    long long now = vt[i];
    move(prv, now);
    for (int j = 0; j < v[num[now]].size(); j++) {
      long long x = v[num[now]][j];
      add(x);
    }
    prv = now;
  }
  if (prv != N * 2) {
    move(prv, N * 2);
  }
  if (!line.empty()) {
    printf("-1");
    return 0;
  }
  printf("%lld", N * 2 - 2);
  return 0;
}
