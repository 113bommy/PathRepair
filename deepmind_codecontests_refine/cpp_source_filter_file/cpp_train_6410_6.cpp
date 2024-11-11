#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
  bool done_something = false;
  stringstream res;
  res << "[";
  for (; begin_iter != end_iter and counter; ++begin_iter) {
    done_something = true;
    counter--;
    res << *begin_iter << ", ";
  }
  string str = res.str();
  if (done_something) {
    str.pop_back();
    str.pop_back();
  }
  str += "]";
  return str;
}
vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
  vector<int> ord(size);
  for (int i = 0; i < size; i++) ord[i] = i;
  sort(ord.begin(), ord.end(), compare);
  return ord;
}
template <typename T>
bool MinPlace(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool MaxPlace(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
template <class TH>
void _dbg(const char* name, TH val) {
  clog << name << ": " << val << endl;
}
template <class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
  while (*names != ',') clog << *names++;
  clog << ": " << curr_val << ", ";
  _dbg(names + 1, vals...);
}
const int MAXN = 110;
long long cnt[MAXN][MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N, M, k, x, y;
  cin >> N >> M >> k >> x >> y;
  long long Q = (2 * N - 2) * M;
  if (N == 1) Q = M;
  long long z = k / Q;
  k %= Q;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cnt[i][j] += z;
      if (i != 0 and i != N - 1) cnt[i][j] += z;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (k > 0) {
        cnt[i][j]++;
        k--;
      }
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < M; j++) {
      if (k > 0) {
        k--;
        cnt[i][j]++;
      }
    }
  }
  long long mm = 1e18;
  long long MM = -1e9;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      mm = min(mm, (long long)cnt[i][j]);
      MM = max(MM, (long long)cnt[i][j]);
    }
  cout << MM << " " << mm << " " << cnt[x - 1][y - 1] << "\n";
}
