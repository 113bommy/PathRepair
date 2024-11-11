#include <bits/stdc++.h>
using namespace std;
template <class T>
istream &operator>>(istream &in, pair<T, T> &p) {
  in >> p.first >> p.second;
  return in;
}
template <class T>
ostream &operator<<(ostream &out, pair<T, T> &p) {
  out << p.first << ' ' << p.second;
  return out;
}
template <class Tuple, std::size_t N>
struct TuplePrinter {
  static void print(ostream &out, const Tuple &t) {
    TuplePrinter<Tuple, N - 1>::print(out, t);
    out << ' ' << get<N - 1>(t);
  }
};
template <class Tuple>
struct TuplePrinter<Tuple, 1> {
  static void print(ostream &out, const Tuple &t) { out << get<0>(t); }
};
template <class... Args>
ostream &operator<<(ostream &out, const tuple<Args...> &p) {
  TuplePrinter<decltype(p), sizeof...(Args)>::print(out, p);
  return out;
}
int N, M, K;
int min_r, max_r, min_c, max_c;
vector<int> row[100005];
vector<int> col[100005];
long long sum = 0;
void solve(int dir, int r, int c) {
  if (dir % 4 == 0) {
    row[r].emplace_back(min_c);
    row[r].emplace_back(max_c);
    sort(row[r].begin(), row[r].end());
    int it = upper_bound(row[r].begin(), row[r].end(), c) - row[r].begin();
    max_c = row[r][it] - 1;
    sum += row[r][it] - c - 1;
    if (c == row[r][it] - 1 && dir > 0) return;
    solve(dir + 1, r, row[r][it] - 1);
  }
  if (dir % 4 == 1) {
    col[c].emplace_back(min_r);
    col[c].emplace_back(max_r);
    sort(col[c].begin(), col[c].end());
    int it = upper_bound(col[c].begin(), col[c].end(), r) - col[c].begin();
    max_r = col[c][it] - 1;
    sum += col[c][it] - r - 1;
    if (r == col[c][it] - 1) return;
    solve(dir + 1, col[c][it] - 1, c);
  }
  if (dir % 4 == 2) {
    row[r].emplace_back(min_c);
    row[r].emplace_back(max_c);
    sort(row[r].begin(), row[r].end(), greater<int>());
    int it = upper_bound(row[r].begin(), row[r].end(), c, greater<int>()) -
             row[r].begin();
    min_c = row[r][it] + 1;
    sum += c - row[r][it] - 1;
    if (c == row[r][it] + 1) return;
    solve(dir + 1, r, row[r][it] + 1);
  }
  if (dir % 4 == 3) {
    col[c].emplace_back(min_r);
    col[c].emplace_back(max_r);
    sort(col[c].begin(), col[c].end(), greater<int>());
    int it = upper_bound(col[c].begin(), col[c].end(), r, greater<int>()) -
             col[c].begin();
    min_r = col[c][it] + 1;
    sum += r - col[c][it] - 1;
    if (r == col[c][it] + 1) return;
    solve(dir + 1, col[c][it] + 1, c);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> N >> M >> K;
  min_r = 1, max_r = N + 1;
  min_c = 0, max_c = M + 1;
  int r, c;
  for (int i = 1; i <= K; i++) {
    cin >> r >> c;
    row[r].emplace_back(c);
    col[c].emplace_back(r);
  }
  solve(0, 1, 1);
  if (sum + 1 == N * M - K)
    cout << "Yes\n";
  else
    cout << "No\n";
}
