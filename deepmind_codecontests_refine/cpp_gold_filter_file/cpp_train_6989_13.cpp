#include <bits/stdc++.h>
using namespace std;
namespace std {
template <>
struct hash<pair<int, int>> {
  inline size_t operator()(const pair<int, int> &v) const {
    hash<int> int_hasher;
    return int_hasher(v.first) ^ int_hasher(v.second);
  }
};
};  // namespace std
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
void print(T t) {
  cout << t << endl;
}
template <typename T, typename... Args>
void print(T t, Args... args) {
  cout << t << " ";
  print(args...);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long k;
  vector<long long> ans;
  ans.push_back(-1);
  cin >> k;
  long long s = 0;
  long long n = 1;
  while ((s - n) < k) {
    long long x = min(k + 1 + n - s, 1000000LL);
    ans.push_back(x);
    s += x;
    n++;
  }
  cout << n << endl;
  for (auto &x : ans) cout << x << " ";
  cout << endl;
  ;
  return 0;
}
