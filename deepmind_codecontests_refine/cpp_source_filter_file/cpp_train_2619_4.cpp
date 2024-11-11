#include <bits/stdc++.h>
using namespace std;
void my_file_in_out() {
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
inline void OK(string t = "") { cerr << "OK " << t << '\n'; }
inline long double time() { return clock() / (long double)CLOCKS_PER_SEC; }
inline void stop(string t = "PROCESS FINISHED") {
  cerr << t << '\n';
  exit(0);
}
const long long M = 998244353;
const int MAXN = 3e3 + 10;
long long bp(long long c, long long st) {
  if (!st) return 1;
  if (st & 1) return (c * bp(c, st - 1)) % M;
  return bp((c * c) % M, st >> 1);
}
long long del(long long c1, long long c2) { return (c1 * bp(c2, M - 2)) % M; }
namespace VECTOR_MAGIC {
template <typename T>
istream &operator>>(istream &inp, vector<T> &a) {
  for (auto &elem : a) inp >> elem;
  return inp;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
  for (auto &elem : a) out << elem << ' ';
  out << endl;
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, vector<vector<T>> &a) {
  for (auto &elem : a) out << elem;
  return out;
}
template <typename T>
void operator++(vector<T> &a) {
  for (auto &el : a) el++;
}
template <typename T>
void operator++(vector<T> &a, T) {
  for (auto &el : a) el++;
}
template <typename T>
void operator--(vector<T> &a) {
  for (auto &el : a) el--;
}
template <typename T>
void operator--(vector<T> &a, T) {
  for (auto &el : a) el--;
}
template <typename T>
void operator+=(vector<T> &a, T X) {
  for (auto &el : a) el += X;
}
}  // namespace VECTOR_MAGIC
using namespace VECTOR_MAGIC;
mt19937 rnd(time(0));
struct point {
  long long x, y, id;
  point() {}
  point(int x, int y) {
    this->x = x;
    this->y = y;
  }
};
point operator-(point A, point B) { return point(A.x - B.x, A.y - B.y); }
long long operator^(point A, point B) { return (A.x * B.y) - (A.y * B.x); }
long long dist(point A, point B) {
  long long dx = A.x - B.x;
  long long dy = A.y - B.y;
  return (dx * dx) + (dy * dy);
}
signed main() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<point> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    a[i].id = i;
  }
  string t;
  cin >> t;
  sort(a.begin(), a.end(), [](point A, point B) {
    if (A.y != B.y) return A.y < B.y;
    return A.x < B.x;
  });
  vector<int> ans;
  vector<bool> used(n, 0);
  used[a[0].id] = 1;
  point tmp = a[0];
  ans.push_back(a[0].id);
  for (int i = 0; i < n - 2; i++) {
    int idx = -1;
    for (int j = 0; j < n && idx == -1; j++)
      if (!used[a[j].id]) idx = j;
    if (t[i] == 'L') {
      for (int j = 0; j < n; j++) {
        if (used[a[j].id]) continue;
        point X1 = a[j] - tmp;
        point X2 = a[idx] - tmp;
        long long cross = X2 ^ X1;
        if (cross == 0) {
          if (dist(tmp, a[j]) < dist(tmp, a[idx])) idx = j;
        } else {
          if (cross < 0) idx = j;
        }
      }
      ans.push_back(a[idx].id);
      used[a[idx].id] = 1;
    } else {
      for (int j = 0; j < n; j++) {
        if (used[a[j].id]) continue;
        point X1 = a[j] - tmp;
        point X2 = a[idx] - tmp;
        long long cross = X2 ^ X1;
        if (cross == 0) {
          if (dist(tmp, a[j]) < dist(tmp, a[idx])) idx = j;
        } else {
          if (cross > 0) idx = j;
        }
      }
      ans.push_back(a[idx].id);
      used[a[idx].id] = 1;
    }
    tmp = a[idx];
  }
  int idx = -1;
  for (int j = 0; j < n && idx == -1; j++)
    if (!used[j]) idx = j;
  ans.push_back(a[idx].id);
  for (auto el : ans) cout << el + 1 << ' ';
  return 0;
}
