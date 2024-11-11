#include <bits/stdc++.h>
using namespace std;
template <class T>
class compare {
 public:
  bool operator()(pair<T, T> &x, pair<T, T> &y) {
    if (x.first == y.first) {
      return x.second > y.second;
    }
    return x.first > y.first;
  }
};
long long power(long long a, int b) {
  long long po = 1;
  while (b) {
    if (b & 1) po *= a;
    a *= a;
    b >>= 1;
  }
  return po;
}
template <class T>
pair<T, T> operator+(const pair<T, T> &a, const pair<T, T> &b) {
  return {a.first + b.first, a.second + b.second};
}
template <class T>
pair<T, T> operator-(const pair<T, T> &a, const pair<T, T> &b) {
  return {a.first - b.first, a.second - b.second};
}
template <class T>
pair<T, T> operator*(const pair<T, T> &a, const pair<T, T> &b) {
  return {a.first * b.first, a.second * b.second};
}
template <class T>
pair<T, T> operator%(const pair<T, T> &a, const pair<T, T> &b) {
  return {a.first % b.first, a.second % b.second};
}
template <class T, class U>
pair<T, T> operator+(const pair<T, T> &a, const U &b) {
  return {a.first + b, a.second + b};
}
template <class T, class U>
pair<T, T> operator*(const pair<T, T> &a, const U &b) {
  return {a.first * b, a.second * b};
}
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(long long N, int pos) { return (bool)(N & (1LL << pos)); }
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, k;
  cin >> n >> k;
  long long ara[n];
  for (int i = 0; i < n; i++) {
    cin >> ara[i];
  }
  long long inc;
  cin >> inc;
  multiset<int> mset;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int now;
    cin >> now;
    mset.insert(now);
    auto it = mset.begin();
    vector<int> del;
    while (k < ara[i]) {
      k += inc;
      ans += *it;
      del.push_back(*it);
      it++;
      if (it == mset.end()) break;
    }
    if (k < now) {
      cout << -1 << "\n";
      return 0;
    }
    for (auto v : del) {
      it = mset.find(v);
      if (it != mset.end()) {
        mset.erase(it);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
