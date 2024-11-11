#include <bits/stdc++.h>
using namespace std;
int n, x, y, x2, y2;
struct rct {
  int x, y, x2, y2;
} v[200005];
struct rctXd {
  int val;
  bool operator<(const rctXd& oth) const {
    if (v[val].x2 == v[oth.val].x2) {
      if (v[val].x == v[oth.val].x) return val < oth.val;
      return v[val].x < v[oth.val].x;
    }
    return v[val].x2 > v[oth.val].x2;
  }
};
struct rctXc {
  int val;
  bool operator<(const rctXc& oth) const {
    if (v[val].x == v[oth.val].x) {
      if (v[val].x2 == v[oth.val].x2) return val < oth.val;
      return v[val].x2 > v[oth.val].x2;
    }
    return v[val].x < v[oth.val].x;
  }
};
struct rctYd {
  int val;
  bool operator<(const rctYd& oth) const {
    if (v[val].y2 == v[oth.val].y2) {
      if (v[val].y == v[oth.val].y) return val < oth.val;
      return v[val].y < v[oth.val].y;
    }
    return v[val].y2 > v[oth.val].y2;
  }
};
struct rctYc {
  int val;
  bool operator<(const rctYc& oth) const {
    if (v[val].y == v[oth.val].y) {
      if (v[val].y2 < v[oth.val].y2) return val < oth.val;
      return v[val].y2 > v[oth.val].y2;
    }
    return v[val].y < v[oth.val].y;
  }
};
void citire() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].x >> v[i].y >> v[i].x2 >> v[i].y2;
  }
}
bool solve(set<rctXc>& Xc, set<rctXd>& Xd, set<rctYc>& Yc, set<rctYd>& Yd) {
  if (Xc.size() == 1) {
    return 1;
  }
  auto itXc = Xc.begin();
  auto itYc = Yc.begin();
  auto itXd = Xd.begin();
  auto itYd = Yd.begin();
  int mXc = v[itXc->val].x2, mXd = v[itXd->val].x, mYd = v[itYd->val].y,
      mYc = v[itYc->val].y2;
  vector<int> deSters;
  int ok = 0;
  itXc++;
  itYc++;
  itXd++;
  itYd++;
  for (int i = 2; i <= min(Xc.size() / 2 + 2, Xc.size()); i++) {
    if (v[itXc->val].x >= mXc) {
      itXc = Xc.begin();
      for (int j = 1; j < i; j++) {
        deSters.push_back(itXc->val);
        itXc++;
      }
      ok = 1;
      break;
    }
    if (v[itXd->val].x2 <= mXd) {
      itXd = Xd.begin();
      for (int j = 1; j < i; j++) {
        deSters.push_back(itXd->val);
        itXd++;
      }
      ok = 1;
      break;
    }
    if (v[itYd->val].y2 <= mYd) {
      itYd = Yd.begin();
      for (int j = 1; j < i; j++) {
        deSters.push_back(itYd->val);
        itYd++;
      }
      ok = 1;
      break;
    }
    if (v[itYc->val].y >= mYc) {
      itYc = Yc.begin();
      for (int j = 1; j < i; j++) {
        deSters.push_back(itYc->val);
        itYc++;
      }
      ok = 1;
      break;
    }
    mXc = max(mXc, v[itXc->val].x2);
    mXd = min(mXd, v[itXd->val].x);
    mYc = max(mYc, v[itYc->val].y2);
    mYd = min(mYd, v[itYd->val].y);
    itXc++;
    itYc++;
    itXd++;
    itYd++;
  }
  if (!ok) return 0;
  set<rctXc> Xc2;
  set<rctXd> Xd2;
  set<rctYc> Yc2;
  set<rctYd> Yd2;
  for (auto it : deSters) {
    Xc.erase({it});
    Xd.erase({it});
    Yc.erase({it});
    Yd.erase({it});
    Xc2.insert({it});
    Xd2.insert({it});
    Yc2.insert({it});
    Yd2.insert({it});
  }
  return solve(Xc, Xd, Yc, Yd) && solve(Xc2, Xd2, Yc2, Yd2);
}
int main() {
  ios::sync_with_stdio(false);
  citire();
  set<rctXc> Xc;
  set<rctXd> Xd;
  set<rctYc> Yc;
  set<rctYd> Yd;
  for (int i = 1; i <= n; i++) {
    Xc.insert({i});
    Xd.insert({i});
    Yc.insert({i});
    Yd.insert({i});
  }
  if (solve(Xc, Xd, Yc, Yd)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
