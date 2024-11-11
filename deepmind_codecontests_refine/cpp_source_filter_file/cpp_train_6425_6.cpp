#include <bits/stdc++.h>
const int MAX = 1E5 + 239 + 1329 + 1000000;
using namespace std;
long long b, a, n, c;
vector<long long> g[100001], ord2;
map<long long, long long> dist;
long long used[100001];
set<pair<long long, long long>> dist10;
long long dist2[210][210], dist3[210][210], z,
    ans = 0, res, res2, devki[1000], malchiki[1000], mas[300000], DO[400000][3];
int k;
long long used2[2001][2];
vector<pair<long long, long long>> rebra, rebra2;
set<pair<long long, long long>> set1;
vector<pair<pair<long long, long long>, long long>> ord;
void pull(long long v, long long l, long long r) {
  if (r - l <= 1) {
    DO[v][1] += DO[v][2];
    DO[v][2] = 0;
  } else {
    DO[v * 2][2] += DO[v][2];
    DO[v * 2 + 1][2] += DO[v][2];
    DO[v][1] += DO[v][2] * (r - l);
    DO[v][2] = 0;
  }
}
long long build(long long v, long long b, long long c) {
  if (c - b <= 1) {
    DO[v][1] = mas[b];
    DO[v][2] = b;
    return DO[v][0];
  }
  DO[v][0] = build(2 * v, b, (b + c) / 2) + build(2 * v + 1, (b + c) / 2, c);
  if (DO[2 * v][1] >= DO[2 * v + 1][1]) {
    DO[v][1] = DO[2 * v][1];
    DO[v][2] = DO[2 * v][2];
  } else {
    DO[v][1] = DO[2 * v + 1][1];
    DO[v][2] = DO[2 * v + 1][2];
  }
  return DO[v][0];
}
long long query(long long v, long long a, long long b, long long c,
                long long d) {
  pull(v, c, d);
  if (a >= d || b <= c) {
    return 0;
  }
  pull(v, c, d);
  if (d - c <= 1 || (a <= c && b >= d)) {
    return DO[v][1];
  }
  pull(v, c, d);
  auto q1 = query(v * 2, a, b, c, (c + d) / 2);
  pull(v, c, d);
  auto q2 = query(v * 2 + 1, a, b, (c + d) / 2, d);
  pull(v, c, d);
  return q1 + q2;
}
void get(long long a, long long l1, long long r1, long long ld, long long rd,
         long long v) {
  if (l1 >= rd || r1 <= ld) {
    return;
  }
  if (l1 <= ld && rd <= r1) {
    DO[v][2] += a;
  } else {
    DO[v][1] += a * ((min(r1, rd) - max(l1, ld)));
    get(a, l1, r1, ld, (ld + rd) / 2, v * 2);
    get(a, l1, r1, (ld + rd) / 2, rd, v * 2 + 1);
  }
  return;
}
long long check2(long long c, long long d) {
  int e = 0, f = -1;
  for (int i = 0; i < b; i++) {
    if ((rebra2[i].first == c && rebra2[i].second == d) ||
        (rebra2[i].first == d && rebra2[i].second == c)) {
    } else {
      if (rebra2[i].first == c) {
        if (f != -1 && f != c) {
          return -1;
        } else {
          f = c;
          e++;
        }
      }
      if (rebra2[i].second == c) {
        if (f != -1 && f != c) {
          return -1;
        } else {
          f = c;
          e++;
        }
      }
      if (rebra2[i].first == d) {
        if (f != -1 && f != d) {
          return -1;
        } else {
          f = d;
          e++;
        }
      }
      if (rebra2[i].second == d) {
        if (f != -1 && f != d) {
          return -1;
        } else {
          f = d;
          e++;
        }
      }
    }
  }
  if (f == -1) {
    return 0;
  }
  return e;
}
long long check(long long c, long long d) {
  int e = 0, f = -1;
  for (int i = 0; i < a; i++) {
    if ((rebra[i].first == c && rebra[i].second == d) ||
        (rebra[i].first == d && rebra[i].second == c)) {
    } else {
      if (rebra[i].first == c) {
        if (f != -1 && f != c) {
          return -1;
        } else {
          f = c;
          e++;
        }
      }
      if (rebra[i].second == c) {
        if (f != -1 && f != c) {
          return -1;
        } else {
          f = c;
          e++;
        }
      }
      if (rebra[i].first == d) {
        if (f != -1 && f != d) {
          return -1;
        } else {
          f = d;
          e++;
        }
      }
      if (rebra[i].second == d) {
        if (f != -1 && f != d) {
          return -1;
        } else {
          f = d;
          e++;
        }
      }
    }
  }
  if (f == -1) {
    return 0;
  }
  return e;
}
int main() {
  long long s1, sqx2, sqy1, sqy2, sqx3, sqx4, sqy3, sqy4,
      res = 0, x, y, sqx5, sqx6, sqy5, sqy6, sq2[10], sq3[10], res2;
  char ch;
  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    cin >> res >> res2;
    rebra.push_back({res, res2});
  }
  for (int i = 0; i < b; i++) {
    cin >> res >> res2;
    rebra2.push_back({res, res2});
    s1 = check(res, res2);
    if (s1 == -1) {
      cout << -1;
      return 0;
    } else if (s1 != 0) {
      ord2.push_back(s1);
    }
  }
  for (int i = 0; i < a; i++) {
    s1 = check2(rebra[i].first, rebra[i].second);
    if (s1 == -1) {
      cout << -1;
      return 0;
    } else if (s1 != 0) {
      ord2.push_back(s1);
    }
  }
  sort(ord2.begin(), ord2.end());
  if (ord2[0] == ord2[ord2.size() - 1]) {
    cout << ord2[0];
  } else {
    cout << 0;
  }
  cin >> a;
  return 0;
}
