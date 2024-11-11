#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const long long inf = 1e18;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(2e5) + 100;
const int ITERS = 80;
int m;
pair<int, int> a[N];
vector<pair<int, int> > group[N];
long long sum_t[N];
int p[N];
double fen_suff[N];
inline long long val(const pair<int, int>& a, const pair<int, int>& b) {
  return 1LL * a.first * b.second - 1LL * b.first * a.second;
}
inline bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return val(a, b) > 0;
}
inline void add_suff(int cp, double val) {
  int pos = lower_bound(p, p + m, cp) - p;
  assert(pos < m && p[pos] == cp);
  while (pos >= 0) {
    if (val < fen_suff[pos]) {
      fen_suff[pos] = val;
    } else {
      break;
    }
    pos = (pos & (pos + 1)) - 1;
  }
}
inline double get_suff(int cp) {
  int pos = lower_bound(p, p + m, cp) - p;
  assert(pos < m && p[pos] == cp);
  double res = 1e100;
  ++pos;
  while (pos < m) {
    res = min(res, fen_suff[pos]);
    pos = (pos | (pos + 1));
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].second);
  }
  sort(a, a + n, cmp);
  for (int i = 0; i < n; ++i) {
    p[i] = a[i].first;
  }
  sort(p, p + n);
  m = unique(p, p + n) - p;
  int i = 0, sz = 0;
  while (i < n) {
    int j = i;
    while (j + 1 < n && val(a[i], a[j + 1]) == 0) {
      ++j;
    }
    for (int z = i; z <= j; ++z) {
      group[sz].push_back(a[z]);
    }
    sort((group[sz]).begin(), (group[sz]).end());
    ++sz;
    i = j + 1;
  }
  for (int i = 0; i < sz; ++i) {
    if (i > 0) {
      sum_t[i] += sum_t[i - 1];
    }
    for (pair<int, int> p : group[i]) {
      sum_t[i] += p.second;
    }
  }
  double l = 0, r = 1;
  for (int it = 0; it < ITERS; ++it) {
    double mid = (l + r) / 2;
    for (int i = 0; i < m; ++i) {
      fen_suff[i] = 1e100;
    }
    bool fl = false;
    for (int i = sz - 1; i >= 0 && !fl; --i) {
      int ptr = ((int)(group[i]).size()) - 1;
      for (int j = ((int)(group[i]).size()) - 1; j >= 0; --j) {
        while (group[i][ptr].first > group[i][j].first) {
          add_suff(
              group[i][ptr].first,
              group[i][ptr].first * (1.0 - mid * sum_t[i] / sum_t[sz - 1]));
          --ptr;
        }
        if (group[i][j].first *
                (1.0 - mid * ((i > 0 ? sum_t[i - 1] : 0) + group[i][j].second) /
                           sum_t[sz - 1]) >
            get_suff(group[i][j].first)) {
          fl = true;
          break;
        }
      }
      while (ptr >= 0) {
        add_suff(group[i][ptr].first,
                 group[i][ptr].first * (1.0 - mid * sum_t[i] / sum_t[sz - 1]));
        --ptr;
      }
    }
    if (fl) {
      r = mid;
      continue;
    }
    for (int i = 0; i < m; ++i) {
      fen_suff[i] = 1e100;
    }
    for (int i = 0; i < sz && !fl; ++i) {
      int ptr = ((int)(group[i]).size()) - 1;
      for (int j = ((int)(group[i]).size()) - 1; j >= 0; --j) {
        while (group[i][ptr].first > group[i][j].first) {
          add_suff(
              group[i][ptr].first,
              group[i][ptr].first * (1.0 - mid * sum_t[i] / sum_t[sz - 1]));
          --ptr;
        }
        if (group[i][j].first *
                (1.0 - mid * ((i > 0 ? sum_t[i - 1] : 0) + group[i][j].second) /
                           sum_t[sz - 1]) >
            get_suff(group[i][j].first)) {
          fl = true;
          break;
        }
      }
      while (ptr >= 0) {
        add_suff(group[i][ptr].first,
                 group[i][ptr].first * (1.0 - mid * sum_t[i] / sum_t[sz - 1]));
        --ptr;
      }
    }
    if (fl) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.18lf\n", (l + r) / 2);
  return 0;
}
