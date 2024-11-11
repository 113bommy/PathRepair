#include <bits/stdc++.h>
using namespace std;
int inf_int = 2e9;
long long inf_ll = 2e18;
const double pi = 3.1415926535898;
template <typename T, typename T1>
void prin(vector<pair<T, T1> >& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i].first << " " << a[i].second << "\n";
  }
}
template <typename T, typename T1>
void prin(set<pair<T, T1> >& a) {
  for (auto it = a.begin(); it != a.end(); it++) {
    cout << it->first << " " << it->second << "\n";
  }
}
template <typename T>
void prin(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i];
    if (i < a.size() - 1)
      cout << " ";
    else
      cout << "\n";
  }
}
template <typename T>
void prin(set<T>& a) {
  for (auto it = a.begin(); it != a.end(); it++) {
    cout << *it << " ";
  }
}
template <typename T>
void prin_new_line(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << "\n";
  }
}
template <typename T, typename T1>
void prin_new_line(vector<pair<T, T1> >& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i].first << " " << a[i].second << "\n";
  }
}
int sum_vec(vector<int>& a) {
  int s = 0;
  for (int i = 0; i < a.size(); i++) {
    s += a[i];
  }
  return s;
}
template <typename T>
T max(vector<T>& a) {
  T ans = a[0];
  for (int i = 1; i < a.size(); i++) {
    ans = max(ans, a[i]);
  }
  return ans;
}
template <typename T>
T min(vector<T>& a) {
  T ans = a[0];
  for (int i = 1; i < a.size(); i++) {
    ans = min(ans, a[i]);
  }
  return ans;
}
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
double s_triangle(double x1, double y1, double x2, double y2, double x3,
                  double y3) {
  return abs(((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2);
}
bool overflow(long long a, long long b) {
  if (a * b / b != a) return true;
  return false;
}
bool debug = 0;
const int maxn = 1e6 + 7;
long long mod = 1e9 + 7;
vector<vector<int> > t(maxn);
void update(int x, int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[x][v] = val;
  } else {
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
      update(x, v * 2, tl, tm, pos, val);
    } else {
      update(x, v * 2 + 1, tl, tm, pos, val);
    }
    t[x][v] = t[x][v * 2] + t[x][v * 2 + 1];
  }
}
int get(int x, int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return 0;
  }
  if (tl == l && tr == r) {
    return t[x][v];
  } else {
    int tm = (tl + tr) >> 1;
    return get(x, v * 2, tl, tm, l, min(r, tm)) +
           get(x, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }
}
void solve() {
  int n;
  scanf("%d", &n);
  vector<pair<int, pair<int, int> > > c;
  int cnt = 0;
  map<int, int> mp;
  int z = 1;
  vector<vector<int> > pl(maxn);
  vector<map<int, int> > pos(maxn);
  for (int i = 1; i <= n; i++) {
    int a, t, x;
    scanf("%d %d %d", &a, &t, &x);
    if (mp[x] == 0) {
      mp[x] = z;
      z++;
    }
    x = mp[x];
    if (a == 1 || a == 2) {
      pl[x].push_back(t);
    }
    c.push_back({a, {t, x}});
  }
  for (int i = 1; i < z; i++) {
    sort(pl[i].begin(), pl[i].end());
    for (int e = 0; e < pl[i].size(); e++) {
      pos[i][pl[i][e]] = e;
    }
    t[i].resize(4 * pl[i].size());
  }
  for (int i = 0; i < c.size(); i++) {
    int a = c[i].first;
    int x = c[i].second.second;
    int t = c[i].second.first;
    if (a == 1) {
      int p = pos[x][t];
      update(x, 1, 0, pl[x].size() - 1, p, 1);
    } else if (a == 2) {
      int p = pos[x][t];
      update(x, 1, 0, pl[x].size() - 1, p, -1);
    } else {
      if (pl[x].size() == 0) {
        printf("0\n");
        continue;
      } else {
        int p =
            distance(pl[x].begin(), lower_bound(pl[x].begin(), pl[x].end(), t));
        p--;
        int val = get(x, 1, 0, pl[x].size() - 1, 0, p);
        printf("%d\n", val);
      }
    }
  }
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
