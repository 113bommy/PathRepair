#include <bits/stdc++.h>
using namespace std;
template <typename T>
void pr(vector<T> &v) {
  for (int i = 0; i < (int)(v).size(); i++) cout << v[i] << " ";
  cout << endl;
}
template <typename T>
void pr(vector<vector<T>> &v) {
  for (int i = 0; i < (int)(v).size(); i++) {
    pr(v[i]);
  }
}
template <typename T>
void re(T &first) {
  cin >> first;
}
template <typename T>
void re(vector<T> &a) {
  for (int i = 0; i < (int)(a).size(); i++) re(a[i]);
}
template <class Arg, class... Args>
void re(Arg &first, Args &...rest) {
  re(first);
  re(rest...);
}
template <typename T>
void pr(T first) {
  cout << first << endl;
}
template <class Arg, class... Args>
void pr(const Arg &first, const Args &...rest) {
  cout << first << " ";
  pr(rest...);
  cout << endl;
}
void ps() { cout << endl; }
template <class T, class... Ts>
void ps(const T &t, const Ts &...ts) {
  cout << t;
  if (sizeof...(ts)) cout << " ";
  ps(ts...);
}
void solve() {
  long long n, d, m;
  re(n, d, m);
  vector<long long> a(n);
  re(a);
  vector<long long> less;
  vector<long long> great;
  for (int i = 0; i < n; i++) {
    if (a[i] <= m)
      less.push_back(a[i]);
    else
      great.push_back(a[i]);
  }
  sort(less.begin(), less.end(), greater<long long>());
  sort(great.begin(), great.end(), greater<long long>());
  long long l = (int)(less).size();
  vector<long long> sum_less(l + 1);
  sum_less[0] = 0;
  for (int i = 0; i < l; i++) {
    sum_less[i + 1] = sum_less[i] + less[i];
  }
  long long sum_great = 0;
  int j = 0;
  long long ans = 0;
  for (long long big = 0; big <= n; big++) {
    long long used = max(0ll, (big - 1) * (d + 1) + 1);
    long long left = n - used;
    if (big > 0 && j < (int)(great).size()) {
      sum_great += great[j];
      j++;
    } else if (big > 0)
      break;
    if (used > n) {
      break;
    }
    ans = max(ans, sum_less[min(left, l)] + sum_great);
  }
  pr(ans);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int tt = 0; tt < t; tt++) {
    solve();
  }
}
