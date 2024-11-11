#include <bits/stdc++.h>
using namespace std;
struct ab {
  int l, m, r;
};
ab a[100005];
string s[3] = {"LM", "MW", "LW"};
int T[100005];
pair<pair<int, int>, int> ss;
map<pair<int, int>, pair<int, int> > D;
bool exitt = 0, ok = 0;
int ans = -109000000;
int P[100005];
int n;
void Sinh1(int k, int l, int r) {
  if (k > r) {
    int a1, a2, a3;
    a1 = a2 = a3 = 0;
    for (int i = l; i <= r; i++) {
      a1 += a[i].l * (T[i] == 0 || T[i] == 2);
      a2 += a[i].m * (T[i] == 1 || T[i] == 0);
      a3 += a[i].r * (T[i] == 1 || T[i] == 2);
    }
    pair<int, int> vv = D[make_pair(a2 - a1, a2 - a3)];
    if (vv.first == 5) {
      if (vv.second < a2) {
        D[make_pair(a2 - a1, a2 - a3)].second = a2;
      }
    } else
      D[make_pair(a2 - a1, a2 - a3)] = make_pair(5, a2);
    return;
  }
  for (int i = 0; i < 3; i++) {
    T[k] = i;
    Sinh1(k + 1, l, r);
  }
}
void Sinh2(int k, int l, int r) {
  if (k > r) {
    int a1, a2, a3;
    a1 = a2 = a3 = 0;
    for (int i = l; i <= r; i++) {
      a1 += a[i].l * (T[i] == 0 || T[i] == 2);
      a2 += a[i].m * (T[i] == 1 || T[i] == 0);
      a3 += a[i].r * (T[i] == 1 || T[i] == 2);
    }
    pair<int, int> vt = D[make_pair(a1 - a2, a3 - a2)];
    if (vt.first != 5) return;
    int vv = vt.second;
    if (vv + a2 >= ans) {
      ok = true;
      for (int i = l; i <= r; i++) P[i] = T[i];
      ss = make_pair(make_pair(a1 - a2, a3 - a2), vv);
      ans = vv + a2;
    }
    return;
  }
  for (int i = 0; i < 3; i++) {
    T[k] = i;
    Sinh2(k + 1, l, r);
  }
}
void Sinh3(int k, int l, int r) {
  if (exitt) return;
  if (k > r) {
    int a1, a2, a3;
    a1 = a2 = a3 = 0;
    for (int i = l; i <= r; i++) {
      a1 += a[i].l * (T[i] == 0 || T[i] == 2);
      a2 += a[i].m * (T[i] == 1 || T[i] == 0);
      a3 += a[i].r * (T[i] == 1 || T[i] == 2);
    }
    if (ss == make_pair(make_pair(a2 - a1, a2 - a3), a2)) {
      exitt = 1;
      for (int i = l; i <= r; i++) P[i] = T[i];
    }
    return;
  }
  for (int i = 0; i < 3; i++) {
    T[k] = i;
    Sinh3(k + 1, l, r);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].m >> a[i].r;
  Sinh1(1, 1, n / 2);
  Sinh2(n / 2 + 1, n / 2 + 1, n);
  Sinh3(1, 1, n / 2);
  if (!ok)
    cout << "Impossible";
  else {
    for (int i = 1; i <= n; i++) cout << s[P[i]] << endl;
  }
}
