#include <bits/stdc++.h>
using namespace std;
const int LOG = 18;
int MUL = 1;
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &v) {
  os << "(";
  os << v.first << "," << v.second << ")";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  int sz = v.size();
  for (int i = 0; i < sz; ++i) {
    os << v[i];
    if (i != sz - 1) os << ",";
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  for (auto it : v) {
    os << it;
  }
  os << "]\n";
  return os;
}
set<pair<int, int> > intervals[LOG];
long long ans[LOG];
long long np1C2(long long x) { return (x * (x + 1)) / 2; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i] /= MUL;
  }
  for (int bit = 0; bit < LOG; bit++) {
    int cur = 0;
    for (int i = 0; i < N; i++) {
      if (A[i] & (1 << bit)) {
        cur++;
      } else {
        if (cur != 0) {
          intervals[bit].insert({i - cur, i - 1});
          ans[bit] += np1C2(cur);
        }
        cur = 0;
      }
    }
    if (cur) {
      intervals[bit].insert({N - cur, N - 1});
      ans[bit] += np1C2(cur);
    }
  }
  int cnt = 0;
  while (M--) {
    int ind, val;
    cin >> ind >> val;
    ind--;
    val /= MUL;
    for (int bit = 0; bit < LOG; bit++) {
      if (val & (1 << bit)) {
        if (intervals[bit].empty()) {
          intervals[bit].insert({ind, ind});
          ans[bit]++;
          continue;
        }
        pair<int, int> I1 = {-1, -1}, I2 = {-1, -1};
        auto it = --intervals[bit].upper_bound({ind, 1e9});
        if (it != intervals[bit].end()) {
          I1 = *it;
          it++;
          if (it != intervals[bit].end()) {
            I2 = *it;
          }
        } else {
          it = intervals[bit].upper_bound({ind, 1e9});
          if (it != intervals[bit].end()) {
            I1 = *it;
          }
        }
        if (I2.first > ind + 1) {
          I2 = {-1, -1};
        }
        if (I1.first > ind + 1 || I1.second < ind - 1) {
          I1 = I2;
          I2 = {-1, -1};
        }
        if (I1 == make_pair(-1, -1)) {
          intervals[bit].insert({ind, ind});
          ans[bit]++;
          continue;
        }
        vector<pair<int, int> > to_rem, to_add;
        if (I2 != make_pair(-1, -1)) {
          to_rem.push_back(I1);
          to_rem.push_back(I2);
          to_add.push_back({I1.first, I2.second});
        } else {
          if (I1.first == ind + 1) {
            to_rem.push_back(I1);
            to_add.push_back({ind, I1.second});
          } else if (I1.second == ind - 1) {
            to_rem.push_back(I1);
            to_add.push_back({I1.first, ind});
          }
        }
        for (pair<int, int> u : to_rem) {
          ans[bit] -= np1C2(u.second - u.first + 1);
          intervals[bit].erase(u);
        }
        for (pair<int, int> u : to_add) {
          ans[bit] += np1C2(u.second - u.first + 1);
          intervals[bit].insert(u);
        }
      } else {
        if (intervals[bit].empty()) {
          continue;
        }
        auto it = --intervals[bit].upper_bound({ind, 1e9});
        if (it == intervals[bit].end()) {
          continue;
        }
        pair<int, int> I = *it;
        if (I.second < ind || I.first > ind) {
          continue;
        }
        vector<pair<int, int> > to_rem, to_add;
        to_rem.push_back(I);
        if (I.first <= ind - 1) {
          to_add.push_back({I.first, ind - 1});
        }
        if (ind + 1 <= I.second) {
          to_add.push_back({ind + 1, I.second});
        }
        for (pair<int, int> u : to_rem) {
          ans[bit] -= np1C2(u.second - u.first + 1);
          intervals[bit].erase(u);
        }
        for (pair<int, int> u : to_add) {
          ans[bit] += np1C2(u.second - u.first + 1);
          intervals[bit].insert(u);
        }
      }
    }
    long long ret = 0;
    for (int bit = 0; bit < LOG; bit++) {
      ret += (1LL << bit) * ans[bit];
    }
    cout << ret << '\n';
  }
  cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
  return 0;
}
