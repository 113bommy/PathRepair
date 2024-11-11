#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e9;
const long long MOD = 1e9 + 7;
mt19937 azino(777);
int ask(int a, int b, int c) {
  cout << "? " << a << " " << b << " " << c << endl;
  int x;
  cin >> x;
  return x;
}
void answer(vector<int>& ans) {
  cout << "! " << ans.size() << " ";
  for (auto& it : ans) cout << it << " ";
  cout << endl;
  return;
}
vector<int> pp(int pos0, int pos1, int pos, int type) {
  vector<int> p(3, -1);
  if (type == 0) {
    int c1 = ask(pos1, pos, pos + 1);
    int c2 = ask(pos1, pos, pos + 2);
    if (c1 == c2) {
      if (c1 == 0) p[0] = p[1] = p[2] = 0;
      if (c1 == 1) p[0] = 1, p[1] = p[2] = 0;
    } else {
      if (c1 == 0) p[0] = p[1] = 0;
      if (c2 == 0) p[0] = p[2] = 0;
      for (auto& i : p)
        if (i == -1) i = 1;
    }
  } else {
    int c1 = ask(pos0, pos, pos + 1);
    int c2 = ask(pos0, pos, pos + 2);
    if (c1 == c2 && c1 == 1)
      p[0] = p[1] = p[2] = 1;
    else if (c1 == c2 && c1 == 0)
      p[0] = 0, p[1] = p[2] = 1;
    else {
      if (c1 == 1) p[0] = p[1] = 1;
      if (c2 == 1) p[0] = p[2] = 1;
      for (auto& i : p)
        if (i == -1) i = 0;
    }
  }
  return p;
}
void solve() {
  int n;
  cin >> n;
  vector<int> z(n);
  int pos0 = 0, pos1 = 0;
  for (int i = 0; i < n; i += 3) {
    z[i] = ask(i + 1, i + 2, i + 3);
    if (z[i])
      pos1 = i;
    else
      pos0 = i;
  }
  vector<int> p0(3, -1), p1(3, -1);
  int c1 = ask(pos1 + 1, pos1 + 2, pos0 + 1);
  int c2 = ask(pos1 + 1, pos1 + 2, pos0 + 2);
  int poss0 = -1, poss1 = -1;
  if (c1 == c2) {
    if (c1 == 0)
      p0[0] = p0[1] = 0;
    else
      p1[0] = p1[1] = 1;
  } else {
    p0[0] = c1, p0[1] = c2;
    if (c1 == 0)
      poss0 = pos0 + 1;
    else
      poss1 = pos0 + 1;
    if (c2 == 0)
      poss0 = pos0 + 2;
    else
      poss1 = pos0 + 2;
  }
  if (p0[0] == -1) {
    c1 = ask(pos1 + 1, pos0 + 1, pos0 + 2);
    c2 = ask(pos1 + 1, pos0 + 1, pos0 + 3);
    if (c1 == c2 && c1 == 0)
      p0[0] = p0[1] = p0[2] = 0;
    else if (c1 == c2 && c1 == 1)
      p0[0] = 1, p0[1] = p0[2] = 0;
    else {
      if (c1 == 0) p0[0] = p0[1] = 0;
      if (c2 == 0) p0[0] = p0[2] = 0;
      for (auto& i : p0)
        if (i == -1) i = 1;
    }
    for (int i = 0; i < 3; ++i)
      if (p0[i] == 0)
        poss0 = pos0 + 1 + i;
      else
        poss1 = pos0 + 1 + i;
    c1 = ask(poss0, pos1 + 1, pos1 + 2);
    c2 = ask(poss0, pos1 + 1, pos1 + 3);
    if (c1 == c2) {
      if (c1 == 1) p1[0] = p1[1] = p1[2] = 1;
      if (c1 == 0) p1[0] = 0, p1[1] = p1[2] = 1;
    } else {
      if (c1 == 1) p1[0] = p1[1] = 1;
      if (c2 == 1) p1[0] = p1[2] = 1;
      for (auto& i : p1)
        if (i == -1) i = 0;
    }
    for (int i = 0; i < 3; ++i)
      if (p1[i] == 0)
        poss0 = pos1 + 1 + i;
      else
        poss1 = pos1 + 1 + i;
  } else {
    if (poss0 != -1) {
      for (int i = 0; i < 3; ++i) p1[i] = ask(poss1, poss0, pos1 + 1 + i);
      p0[2] = ask(poss1, poss0, pos0 + 3);
    } else {
      c1 = ask(pos0 + 1, pos1 + 1, pos1 + 2);
      c2 = ask(pos0 + 1, pos1 + 1, pos1 + 3);
      if (c1 == c2 && c1 == 1)
        p1[0] = p1[1] = p1[2] = 1;
      else if (c1 == c2 && c1 == 0)
        p1[0] = 0, p1[1] = p1[2] = 1;
      else {
        if (c1 == 1) p1[0] = p1[1] = 1;
        if (c2 == 1) p1[0] = p1[2] = 1;
        for (auto& i : p1)
          if (i == -1) i = 0;
      }
      for (int i = 0; i < 3; ++i)
        if (p1[i] == 0)
          poss0 = pos1 + 1 + i;
        else
          poss1 = pos1 + 1 + i;
      c1 = ask(poss1, pos0 + 1, pos0 + 2);
      c2 = ask(poss1, pos0 + 1, pos0 + 3);
      if (c1 == c2) {
        if (c1 == 0) p0[0] = p0[1] = p0[2] = 0;
        if (c1 == 1) p0[0] = 1, p0[1] = p0[2] = 0;
      } else {
        if (c1 == 0) p0[0] = p0[1] = 0;
        if (c2 == 0) p0[0] = p0[2] = 0;
        for (auto& i : p0)
          if (i == -1) i = 1;
      }
      for (int i = 0; i < 3; ++i)
        if (p0[i] == 0)
          poss0 = pos0 + 1 + i;
        else
          poss1 = pos0 + 1 + i;
    }
  }
  vector<int> ans;
  for (int i = 0; i < 3; ++i)
    if (p0[i] == 0) ans.emplace_back(pos0 + i + 1);
  for (int i = 0; i < 3; ++i)
    if (p1[i] == 0) ans.emplace_back(pos1 + i + 1);
  for (int i = 0; i < n; i += 3) {
    if (i == pos0 || i == pos1) continue;
    auto it = pp(poss0, poss1, i + 1, z[i]);
    for (int j = 0; j < 3; ++j)
      if (it[j] == 0) ans.emplace_back(i + 1 + j);
  }
  answer(ans);
}
signed main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
    cout << '\n';
  }
  return 0;
}
