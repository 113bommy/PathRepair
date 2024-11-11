#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int a, b, c, d, i, j, n, m, k;
vector<pair<int, int> > len[90001], vec;
vector<int> ls;
inline int check(int d) {
  for (int _n(((int)((ls).size())) - 1), i(0); i <= _n; i++) len[ls[i]].clear();
  ls.clear();
  for (int _n(d), first(0); first <= _n; first++) {
    for (int _n(d), second(0); second <= _n; second++) {
      if (first * first + second * second > d * d) break;
      len[first * first + second * second].push_back(make_pair(first, second));
    }
  }
  for (int _n((90000)), i(1); i <= _n; i++) {
    if ((int)((len[i]).size())) ls.push_back(i);
  }
  return (int)((ls).size());
}
inline pair<int, int> operator+(const pair<int, int> &a,
                                const pair<int, int> &b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
inline pair<int, int> operator-(const pair<int, int> &a,
                                const pair<int, int> &b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
pair<int, int> dp[31][201][201];
bool was = 0;
inline bool adjust(pair<int, int> need, int k) {
  if (!was) {
    was = 1;
    for (int _n((31) - 1), i(0); i <= _n; i++)
      for (int _n((201) - 1), j(0); j <= _n; j++)
        for (int _n((201) - 1), z(0); z <= _n; z++)
          dp[i][j][z] = make_pair(1000000000, 1000000000);
    dp[0][100][100] = make_pair(0, 0);
    for (int _n((k)-1), i(0); i <= _n; i++) {
      for (int _n(100), first(-100); first <= _n; first++) {
        for (int _n(100), second(-100); second <= _n; second++) {
          if (dp[i][first + 100][second + 100].first != 1000000000) {
            int cl = ls[i];
            pair<int, int> rr = make_pair(first, second);
            for (int _n(((int)((len[cl]).size())) - 1), z(0); z <= _n; z++) {
              for (int _n((4) - 1), o(0); o <= _n; o++) {
                pair<int, int> t = len[cl][z];
                if (o & 1) t.first = -t.first;
                if (o & 2) t.second = -t.second;
                pair<int, int> r = rr + t;
                if (abs(r.first) > 100 || abs(r.second) > 100) continue;
                dp[i + 1][r.first + 100][r.second + 100] = t;
              }
            }
          }
        }
      }
    }
  }
  pair<int, int> nn = make_pair(-need.first, -need.second);
  if (dp[k][nn.first + 100][nn.second + 100].first == 1000000000) return 0;
  while (nn != make_pair(0, 0)) {
    vec.push_back(dp[k][nn.first + 100][nn.second + 100]);
    nn = nn - dp[k--][nn.first + 100][nn.second + 100];
  }
  return 1;
}
inline int vv(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first * b.second - b.first * a.second;
}
inline int scal(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first * b.first + a.second * b.second;
}
inline int cetv(const pair<int, int> &a) {
  if (a.second == 0 && a.first >= 0)
    return 1;
  else if (a.first > 0 && a.second > 0)
    return 2;
  else if (a.first == 0 && a.second > 0)
    return 3;
  else if (a.first < 0 && a.second > 0)
    return 4;
  else if (a.second == 0 && a.first < 0)
    return 5;
  else if (a.first < 0 && a.second < 0)
    return 6;
  else if (a.first == 0 && a.second < 0)
    return 7;
  else
    return 8;
}
inline bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if (cetv(a) != cetv(b)) return cetv(a) < cetv(b);
  int rr = vv(a, b);
  if (rr != 0) return rr > 0;
  return scal(a, a) < scal(b, b);
}
pair<int, int> dd[33][33][81][81];
int main() {
  scanf("%d", &n);
  puts("YES");
  int l = 0, r = 200;
  while (r - l > 1) {
    int xx = (r + l) / 2;
    if (check(xx) < n)
      l = xx;
    else
      r = xx;
  }
  if (check(l) < n) ++l;
  ++l;
  ++l;
  check(l);
  while (check(l) < 32) ++l;
  if (n <= 30) {
    for (int _n((33) - 1), i(0); i <= _n; i++)
      for (int _n((33) - 1), j(0); j <= _n; j++)
        for (int _n((81) - 1), z(0); z <= _n; z++)
          for (int _n((81) - 1), o(0); o <= _n; o++)
            dd[i][j][z][o] = make_pair(1000000000, 1000000000);
    dd[0][0][40][40] = make_pair(0, 0);
    for (int _n((32) - 1), i(0); i <= _n; i++) {
      for (int _n((i + 1) - 1), j(0); j <= _n; j++) {
        for (int _n(40), first(-40); first <= _n; first++) {
          for (int _n(40), second(-40); second <= _n; second++) {
            if (dd[i][j][first + 40][second + 40].first != 1000000000) {
              int cl = ls[i];
              pair<int, int> rr = make_pair(first, second);
              dd[i + 1][j][rr.first + 40][rr.second + 40] = make_pair(0, 0);
              for (int _n(((int)((len[cl]).size())) - 1), z(0); z <= _n; z++) {
                for (int _n((4) - 1), o(0); o <= _n; o++) {
                  pair<int, int> t = len[cl][z];
                  if (o & 1) t.first = -t.first;
                  if (o & 2) t.second = -t.second;
                  pair<int, int> r = rr + t;
                  if (abs(r.first) > 40 || abs(r.second) > 40) continue;
                  dd[i + 1][j + 1][r.first + 40][r.second + 40] = t;
                }
              }
            }
          }
        }
      }
    }
    pair<int, int> nn = make_pair(0, 0);
    a = n;
    b = 32;
    while (b >= 0 && dd[b][a][40][40].first != 1000000000) --b;
    ++b;
    while (a) {
      vec.push_back(dd[b][a][nn.first + 40][nn.second + 40]);
      c = 1;
      if (vec.back() == make_pair(0, 0)) vec.pop_back(), c = 0;
      nn = nn - dd[b][a][nn.first + 40][nn.second + 40];
      a -= c;
      --b;
    }
    sort((vec).begin(), (vec).end(), cmp);
    pair<int, int> t = make_pair(0, 0);
    for (int _n(((int)((vec).size())) - 1), i(0); i <= _n; i++) {
      printf("%d %d\n", t.first, t.second);
      t = t + vec[i];
    }
    exit(0);
  }
  int tot = 30;
  c = 0;
  d = n;
  while (1) {
    ++c;
    if (c % 30 == 0) {
      ls.erase(ls.begin());
    }
    vec.clear();
    pair<int, int> t = make_pair(0, 0);
    for (int i = (n - 1), _b = (tot); i >= _b; i--) {
      pair<int, int> rr = make_pair(1000000000, 1000000000);
      a = 1000000000;
      for (int _n(((int)((len[ls[i]]).size())) - 1), j(0); j <= _n; j++) {
        pair<int, int> rz = len[ls[i]][j];
        for (int _n((4) - 1), o(0); o <= _n; o++) {
          pair<int, int> tt = rz;
          if (o & 1) tt.first = -tt.first;
          if (o & 2) tt.second = -tt.second;
          pair<int, int> oo = t + tt;
          if ((abs(oo.first) + abs(oo.second) < a) ||
              (abs(oo.first) + abs(oo.second) == a &&
               rand() % (int)((len[ls[i]]).size()) == 0)) {
            a = abs(oo.first) + abs(oo.second);
            rr = tt;
          }
        }
      }
      t = t + rr;
      vec.push_back(rr);
    }
    if (adjust(t, min(tot, n))) break;
  }
  sort((vec).begin(), (vec).end(), cmp);
  pair<int, int> t = make_pair(0, 0);
  for (int _n(((int)((vec).size())) - 1), i(0); i <= _n; i++) {
    printf("%d %d\n", t.first, t.second);
    t = t + vec[i];
  }
}
