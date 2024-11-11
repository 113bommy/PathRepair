#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = (unsigned long long)(-1) >> 1;
const long double pi = acos(-1.0);
class point {
 public:
  long long x;
  long long y;
  bool operator<(const point other) const {
    if (x == other.x) return y < other.y;
    return x < other.x;
  }
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
template <typename T, typename U>
void mapto(vector<T>& domain, vector<U>& range, function<U(T)> lambda) {
  int S = domain.size();
  range.resize(S);
  for (int i = 0; i < S; ++i) {
    range[i] = lambda(domain[i]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w,
      x, y, z;
  string str;
  cin >> n >> a >> b >> t;
  cin >> str;
  vector<long long> forw;
  vector<long long> backw;
  for (auto ch : str) {
    forw.push_back((long long)(ch == 'w') * b);
  }
  for (auto it = forw.rbegin(); it != forw.rend(); it++) {
    backw.push_back(*it);
  }
  int first = forw[0] + 1;
  if (first > t) {
    cout << 0;
    return 0;
  }
  t -= first;
  vector<long long> ftime, btime;
  long long curr_time = -first - a;
  long long best = 0;
  for (auto ii : forw) {
    curr_time += a + ii + 1;
    ftime.push_back(curr_time);
    if (curr_time <= t) {
      best++;
    }
  }
  curr_time = 0;
  long long newbest = 1;
  for (auto ii : backw) {
    curr_time += a + ii + 1;
    btime.push_back(curr_time);
    if (curr_time <= t) {
      newbest++;
    }
  }
  best = max(best, newbest);
  if (best >= n) {
    cout << n;
    return 0;
  }
  f = 0;
  long long bc = -1;
  while (ftime[f] <= t) {
    f++;
  }
  f--;
  newbest = f + 1;
  while (f) {
    while (btime[bc + 1] + ftime[f] + min(f, bc + 2) * a <= t) {
      bc++;
      newbest++;
      best = max(newbest, best);
    }
    f--;
    newbest--;
  }
  cout << best;
  return 0;
}
