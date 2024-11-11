#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
const long long mod = 1000000000 + 7;
int m;
int n;
long long ans;
int nint() {
  int x;
  scanf("%d", &x);
  return x;
}
long long maxhp[100500];
long long lasttime[100500];
long long lasthp[100500];
long long regen[100500];
long long bounty, inc;
long long damage;
long long curt;
long long getHp(int i) {
  return min(maxhp[i], lasthp[i] + regen[i] * (curt - lasttime[i]));
}
long long getTime(int i) {
  if (regen[i] == 0) return 2 * mod + 1;
  long long d = damage + 1 - getHp(i);
  long long ans = curt + (d + regen[i] - 1) / regen[i];
  return ans;
}
bool f(int a, int b) {
  long long t1 = getTime(a);
  long long t2 = getTime(b);
  if (t1 != t2) return t1 < t2;
  return a < b;
}
set<int, bool (*)(int, int)> s1(f);
set<int> s2;
void check() { ans = max(ans, (bounty + curt * inc) * ((int)(s1).size())); }
void setHp(int i, long long hp, bool opa = false) {
  if (!opa) {
    if (s2.count(i))
      s2.erase(i);
    else
      s1.erase(i);
  }
  lasthp[i] = hp;
  lasttime[i] = curt;
  if (hp <= damage) {
    if (regen[i] == 0 && inc) {
      cout << -1;
      exit(0);
    }
    s1.insert(i);
  } else
    s2.insert(i);
}
void updateS1() {
  int x = *s1.begin();
  long long tt = getTime(x);
  vector<int> v;
  for (int o : s1) {
    if (getTime(o) != tt) break;
    v.push_back(o);
  }
  curt = tt - 1;
  check();
  for (int x : v) {
    s1.erase(x);
    s2.insert(x);
  }
  curt = tt;
}
void tryUpdate(long long nt) {
  while (((int)(s1).size())) {
    int x = *s1.begin();
    long long tt = getTime(x);
    if (tt <= nt)
      updateS1();
    else
      break;
  }
  if (curt < nt) {
    curt = nt - 1;
    check();
  }
  curt = nt;
}
int main() {
  cin >> n >> m;
  cin >> bounty >> inc >> damage;
  for (int i = 0; i < (n); i++) {
    maxhp[i] = nint();
    lasthp[i] = nint();
    regen[i] = nint();
    if (damage >= maxhp[i] && inc) {
      cout << -1;
      return 0;
    }
    setHp(i, lasthp[i], true);
  }
  check();
  vector<pair<int, pair<int, int> > > q;
  for (int i = 0; i < (m); i++) {
    pair<int, pair<int, int> > x;
    x.first = nint();
    x.second.first = nint();
    x.second.second = nint();
    q.push_back(x);
  }
  sort((q).begin(), (q).end());
  for (auto o : q) {
    int tt = o.first;
    int id = o.second.first - 1;
    int hp = o.second.second;
    if (curt < tt) tryUpdate(tt);
    setHp(id, hp);
  }
  tryUpdate(2 * mod);
  cout << ans;
}
