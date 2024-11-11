#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
set<pair<long long, long long> > sp;
void add(long long l, long long r) {
  auto it = sp.lower_bound({l, 0});
  it--;
  long long L;
  if (it->second + 1 >= l) {
    L = it->first;
  } else {
    it++;
    L = min(l, it->first);
  }
  auto cur = it;
  while (cur->first <= r + 1) {
    auto tmp = cur;
    cur++;
    r = max(r, tmp->second);
    sp.erase(tmp);
  }
  sp.insert({L, r});
}
void del(long long l, long long r) {
  auto it = sp.lower_bound({l, 0});
  it--;
  if (it->second < l) it++;
  vector<pair<long long, long long> > vp;
  while (it->first <= r) {
    auto tmp = it;
    it++;
    if (tmp->first < l) vp.push_back({tmp->first, l - 1});
    if (tmp->second > r) vp.push_back({r + 1, tmp->second});
    sp.erase(tmp);
  }
  for (auto p : vp) sp.insert(p);
}
void rev(long long l, long long r) {
  auto it = sp.lower_bound({l, 0});
  it--;
  if (it->second < l) it++;
  vector<pair<long long, long long> > vp;
  if (r < it->first) {
    add(l, r);
    return;
  }
  auto zz = it;
  zz--;
  pair<long long, long long> pre = *zz;
  while (it->first <= r) {
    auto tmp = it;
    it++;
    if (max(l, pre.second + 1) < tmp->first) {
      vp.push_back({max(l, pre.second + 1), tmp->first - 1});
    }
    if (r < it->first && tmp->second < r) {
      vp.push_back({tmp->second + 1, r});
    }
    if (tmp->first < l) vp.push_back({tmp->first, l - 1});
    if (tmp->second > r) vp.push_back({r + 1, tmp->second});
    pre = *tmp;
    sp.erase(tmp);
  }
  for (int i = 1; i < (int)vp.size() - 1; i++) {
    sp.insert(vp[i]);
  }
  if (!vp.empty()) add(vp[0].first, vp[0].second);
  if (vp.size() > 1) add(vp.back().first, vp.back().second);
}
void pp() {
  for (auto p : sp)
    if (p.first < 100) {
      printf("%lld ~ %lld   ", p.first, p.second);
    }
  puts("");
}
void fmain(int tid) {
  scanf("%d", &n);
  sp.insert({-1, -1});
  sp.insert({(1LL << 60), (1LL << 60)});
  debug = n == 1000;
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    int t;
    long long r, l;
    scanf("%d%lld%lld", &t, &l, &r);
    if (t == 1)
      add(l, r);
    else if (t == 2)
      del(l, r);
    else
      rev(l, r);
    if (!debug) {
      auto it = sp.begin();
      it++;
      if (it->first != 1)
        puts("1");
      else
        printf("%lld\n", it->second + 1);
    } else if (i == 99) {
      printf("%d %lld %lld\n", t, l, r);
      pp();
      return;
    }
  }
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
