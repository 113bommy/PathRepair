#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace std {
template <>
struct hash<pair<int, int>> {
  size_t operator()(const pair<int, int> &x) const {
    long long P = 38923, Q = 109797901;
    return (size_t)((x.first * P + x.second) % Q);
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
  string s;
  cin >> s;
  int n = (int)(s).size();
  string t;
  int cntz = 0, scnto = 0;
  for (int i = max((int)n - 1, (int)-1); i > min((int)n - 1, (int)-1);
       i += -1) {
    if (s[i] == '0')
      t.push_back('0'), cntz++;
    else {
      if (cntz >= scnto)
        t.push_back('1');
      else
        t.push_back('0'), cntz++;
      scnto++;
    }
  }
  reverse(t.begin(), t.end());
  cout << t << endl;
  return 0;
}
