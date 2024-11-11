#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2;
const double EPS = 1e-8;
const long long MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const long long oo = 1e18;
const double foo = 1e30;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcounll(s);
}
template <class T>
T sqr(T x) {
  return x * x;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
int n, k, m, a[MAXN];
set<int> pos;
set<pair<long long, int> > house[MAXN];
priority_queue<pair<long long, pair<int, int> > > st;
long long curT;
void addM(pair<long long, pair<int, int> > now) {
  int id = now.second.first;
  pos.insert(id);
  if (house[id].empty()) {
    pos.insert(id);
  }
  house[id].insert(make_pair(-now.first, now.second.second));
}
int cmp(pair<long long, int> a, pair<long long, int> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first > b.first;
}
int main() {
  cin >> n >> k >> m;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    pos.insert(a[i]);
    house[a[i]].insert(make_pair(0ll, i + 1));
  }
  for (int i = 0; i < m; i++) {
    long long t;
    int ss, ee;
    scanf("%I64d%d%d", &t, &ss, &ee);
    while (!st.empty() && -st.top().first <= t) {
      addM(st.top());
      st.pop();
    }
    curT = max(curT, t);
    if (!pos.empty()) {
      long long tw = curT - t;
      set<int>::iterator it = pos.lower_bound(ss);
      long long dis = oo;
      int now = -1;
      if (it != pos.end()) {
        dis = abs(*it - ss);
        now = *it;
      }
      if (it != pos.begin()) {
        it--;
        if (!~now || dis > abs(*it - ss)) {
          dis = abs(*it - ss);
          now = *it;
        } else if (~now && dis == abs(*it - ss)) {
          if (cmp(*house[now].begin(), *house[*it].begin()) == 1) {
            now = *it;
          }
        }
      }
      int car = (*house[now].begin()).second;
      house[now].erase(house[now].begin());
      if (house[now].empty()) {
        pos.erase(now);
      }
      printf("%d %I64d\n", car, dis + tw);
      st.push(make_pair(-(t + tw + dis + (long long)abs(ee - ss)),
                        make_pair(ee, car)));
    } else {
      pair<long long, pair<int, int> > cur = st.top();
      curT = max(curT, -cur.first);
      st.pop();
      addM(cur);
      while (!st.empty() && st.top().first == cur.first) {
        addM(st.top());
        st.pop();
      }
      assert(!pos.empty());
      long long tw = curT - t;
      set<int>::iterator it = pos.lower_bound(ss);
      long long dis = oo;
      int now = -1;
      if (it != pos.end()) {
        dis = abs(*it - ss);
        now = *it;
      }
      if (it != pos.begin()) {
        it--;
        if (!~now || dis > abs(*it - ss)) {
          dis = abs(*it - ss);
          now = *it;
        } else if (~now && dis == abs(*it - ss)) {
          if (cmp(*house[now].begin(), *house[*it].begin()) == 1) {
            now = *it;
          }
        }
      }
      int car = (*house[now].begin()).second;
      house[now].erase(house[now].begin());
      if (house[now].empty()) {
        pos.erase(now);
      }
      printf("%d %I64d\n", car, dis + tw);
      st.push(make_pair(-(-cur.first + dis + (long long)abs(ee - ss)),
                        make_pair(ee, car)));
    }
  }
  return 0;
}
