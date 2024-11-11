#include <bits/stdc++.h>
using namespace std;
void stress();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  stress();
}
const long long inf = 1e9 + 1;
struct node {
  long long sum;
  long long p;
  node *l, *r;
  node() : sum(0), p(inf), l(0), r(0){};
};
void push(node *&t, long long tl, long long mid, long long tr) {
  if (t->p != inf) {
    if (t->l == 0) t->l = new node();
    if (t->r == 0) t->r = new node();
    t->l->sum = (mid - tl + 1) * t->p;
    t->r->sum = (tr - mid) * t->p;
    t->r->p = t->l->p = t->p;
    t->p = inf;
  }
}
long long getsum(node *&t, long long tl, long long tr, long long l,
                 long long r) {
  if (tl == l && tr == r) return t->sum;
  long long mid = tl + tr >> 1;
  push(t, tl, mid, tr);
  long long ans = 0;
  if (l <= mid) ans += getsum(t->l, tl, mid, l, min(r, mid));
  if (r > mid) ans += getsum(t->r, mid + 1, tr, max(l, mid + 1), r);
  return ans;
}
long long sum(node *t) {
  if (!t) return 0;
  return t->sum;
}
void update(node *&t, long long tl, long long tr, long long l, long long r,
            long long x) {
  if (tl == l && tr == r) {
    t->sum = (tr - tl + 1) * x;
    t->p = x;
    return;
  }
  long long mid = tl + tr >> 1;
  push(t, tl, mid, tr);
  if (l <= mid) update(t->l, tl, mid, l, min(r, mid), x);
  if (r > mid) update(t->r, mid + 1, tr, max(l, mid + 1), r, x);
  t->sum = sum(t->l) + sum(t->r);
}
void solveE() {
  node *t = new node();
  t->p = 0;
  long long q;
  cin >> q;
  set<pair<long long, long long>> events;
  while (q--) {
    long long type;
    cin >> type;
    if (type == 1) {
      long long T, s;
      cin >> T >> s;
      events.insert({T, s});
      long long to = 1e9;
      auto it = events.upper_bound({T, s});
      if (it != events.end()) to = it->first - 1;
      update(t, 1, 1e9, T, to, s);
    } else if (type == 2) {
      long long T;
      cin >> T;
      auto it = events.lower_bound({T, -1e9 - 1});
      long long val = 0;
      if (it != events.begin()) {
        auto it2 = prev(it);
        val = it2->second;
      }
      long long to = 1e9;
      if (next(it) != events.end()) {
        auto it2 = next(it);
        to = it2->first;
      }
      update(t, 1, 1e9, T, to, val);
      events.erase(it);
    } else {
      long long l, r, v;
      cin >> l >> r >> v;
      if (getsum(t, 1, 1e9, l, r - 1) > v)
        cout << -1;
      else {
        long long asd = 50;
        double ll = l, rr = r;
        while (asd--) {
          double mid = (ll + rr) / 2;
          long long mm = mid;
          double val = 0;
          if (mm > l) {
            val += getsum(t, 1, 1e9, l, mm - 1);
          }
          double res = mid - mm;
          auto it = events.upper_bound({mm, -inf});
          long long vv = 0;
          if (it != events.begin()) {
            it--;
            vv = it->second;
          }
          val += vv * res;
          if (val >= v) {
            rr = mid;
          } else
            ll = mid;
        }
        cout << rr - l << endl;
      }
    }
  }
}
void stress() {
  string s;
  cin >> s;
  if (s.size() % 2 == 1) {
    string l = s.substr(0, s.size() / 2);
    string r = s.substr((s.size() + 1) / 2, s.size());
    if (l != r) {
      cout << 2 << endl;
    } else {
      set<char> sss;
      for (auto it : l) sss.insert(it);
      if (sss.size() > 1) {
        cout << 3;
      } else
        cout << "Impossible";
    }
  } else {
    string l = s.substr(0, s.size() / 2);
    string r = s.substr((s.size() + 1) / 2, s.size());
    if (l != r)
      cout << 1;
    else {
      set<char> sss;
      for (auto it : l) sss.insert(it);
      if (sss.size() > 1) {
        s += s;
        long long len = s.size() / 2;
        for (long long i = 1; i < s.size(); i++) {
          bool fl = true;
          bool dif = false;
          for (long long j = 0; j < len / 2; j++) {
            if (s[i + j] != l[j]) dif = true;
            if (s[i + j] != s[len + i - j - 1]) fl = false;
          }
          if (fl && dif) {
            cout << 1;
            return;
          }
        }
        cout << 3;
      } else
        cout << "Impossible";
    }
  }
}
