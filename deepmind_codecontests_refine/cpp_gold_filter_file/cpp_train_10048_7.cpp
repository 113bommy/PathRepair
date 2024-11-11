#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = ((unsigned long long)(-1) >> 1);
class point {
 public:
  long long x;
  long long y;
  bool operator<(const point other) const { return x < other.x; }
  friend ostream& operator<<(ostream& out, const point p);
  friend istream& operator>>(istream& in, point& number);
};
ostream& operator<<(ostream& out, const point p) {
  return out << p.x << " " << p.y;
}
istream& operator>>(istream& in, point& p) { return in >> p.x >> p.y; }
class integer_binary_search {
 private:
  long long left;
  long long right;

 public:
  long long middle;
  bool moveup;
  integer_binary_search(long long l = 0, long long r = INF)
      : left(l), right(r), middle((l + r) >> 1), moveup(false) {}
  void update() {
    if (moveup) {
      left = middle;
    } else {
      right = middle;
    }
    middle = (left + right) >> 1;
  }
  bool in_progress() { return right - left != 1; }
};
template <typename T>
void read_vector(vector<T>& arg, int size = 200000) {
  arg.resize(size);
  for (int i = 0; i < size; ++i) {
    cin >> arg[i];
  }
}
template <typename T>
inline void sort_vector(vector<T>& arg) {
  sort(arg.begin(), arg.end());
}
void write_int_list(int args, ...) {
  va_list lst;
  va_start(lst, args);
  for (int i = 0; i < args; ++i) {
    cout << va_arg(lst, long long) << " ";
  }
  va_end(lst);
  cout << "\n";
}
template <typename T>
void write_vector(vector<T>& lst) {
  for (auto i : lst) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w,
      x, y, z;
  vector<point> data;
  vector<long long> l_max_y;
  vector<long long> l_min_y;
  vector<long long> r_max_y;
  vector<long long> r_min_y;
  vector<long long> l_max_abs_y;
  vector<long long> r_max_abs_y;
  cin >> n;
  read_vector(data, n);
  sort_vector(data);
  long long best = data[n - 1].x - data[0].x, minimy = INF, maximy = -INF;
  l_max_y.push_back(-INF);
  l_min_y.push_back(INF);
  l_max_abs_y.push_back(0);
  for (auto iii : data) {
    minimy = min(minimy, iii.y);
    maximy = max(maximy, iii.y);
    l_max_y.push_back(maximy);
    l_min_y.push_back(minimy);
    l_max_abs_y.push_back(max(l_max_abs_y[l_max_abs_y.size() - 1], abs(iii.y)));
  }
  r_max_y.push_back(-INF);
  r_min_y.push_back(INF);
  r_max_abs_y.push_back(0);
  minimy = INF, maximy = -INF;
  for (auto it = data.rbegin(); it != data.rend(); it++) {
    minimy = min(minimy, it->y);
    maximy = max(maximy, it->y);
    r_max_y.push_back(maximy);
    r_min_y.push_back(minimy);
    r_max_abs_y.push_back(max(r_max_abs_y[r_max_abs_y.size() - 1], abs(it->y)));
  }
  best = min(best, maximy - minimy);
  if (!best) {
    cout << 0;
    return 0;
  }
  integer_binary_search bins(-1, best * best);
  for (; bins.in_progress(); bins.update()) {
    long long var = bins.middle;
    bins.moveup = true;
    for (i = 0; i < n; i++) {
      long long bound = min(4 * data[i].x * data[i].x, var), save;
      if (data[i].x <= 0) {
        integer_binary_search b2(i, n);
        for (; b2.in_progress(); b2.update()) {
          b2.moveup = ((data[b2.middle].x - data[i].x) *
                           (data[b2.middle].x - data[i].x) <=
                       bound);
        }
        save = b2.middle;
      } else {
        integer_binary_search b2(-1, i);
        for (; b2.in_progress(); b2.update()) {
          b2.moveup = ((data[b2.middle].x - data[i].x) *
                           (data[b2.middle].x - data[i].x) >
                       bound);
        }
        save = b2.middle + 1;
      }
      m = max(i, save);
      z = min(i, save);
      long long curr_max_y = max(l_max_y[z], r_max_y[n - m - 1]);
      long long curr_min_y = min(l_min_y[z], r_min_y[n - m - 1]);
      long long curr_abs_y = max(l_max_abs_y[z], r_max_abs_y[n - m - 1]);
      if (((curr_max_y - curr_min_y) * (curr_max_y - curr_min_y) <= var ||
           curr_min_y == INF) &&
          curr_abs_y * curr_abs_y + data[i].x * data[i].x <= var) {
        bins.moveup = false;
        break;
      }
    }
  }
  cout << bins.middle + 1;
  return 0;
}
