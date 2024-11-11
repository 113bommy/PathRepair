#include <bits/stdc++.h>
using namespace std;
template <typename T>
void pr(vector<T> &v) {
  for (int i = 0; i < (int)(v).size(); i++) cout << v[i] << " ";
  cout << '\n';
  ;
}
template <typename T>
void pr(vector<vector<T>> &v) {
  for (int i = 0; i < (int)(v).size(); i++) {
    pr(v[i]);
  }
}
template <typename T>
void re(T &x) {
  cin >> x;
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
void pr(T x) {
  cout << x << '\n';
  ;
}
template <class Arg, class... Args>
void pr(const Arg &first, const Args &...rest) {
  cout << first << " ";
  pr(rest...);
  cout << '\n';
  ;
}
void ps() {
  cout << '\n';
  ;
}
template <class T, class... Ts>
void ps(const T &t, const Ts &...ts) {
  cout << t;
  if (sizeof...(ts)) cout << " ";
  ps(ts...);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  re(n);
  vector<vector<int>> vals(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    cin >> vals[i][0] >> vals[i][1];
    vals[i][2] = i;
  }
  sort(vals.begin(), vals.end());
  int mx_p = -1;
  int mx_p_index = 0;
  int mx = -1;
  int mx_index = -1;
  for (int i = 0; i < n; i++) {
    if (vals[i][1] <= mx) {
      cout << vals[i][2] + 1 << '\n';
      ;
      return 0;
    } else if (vals[i][0] <= mx_p) {
      cout << vals[mx_p_index][2] + 1 << '\n';
      ;
      return 0;
    }
    if (mx + 1 > mx_p) {
      mx_p_index = i;
      mx_p = max(vals[i][0], mx + 1);
    }
    if (vals[i][1] > mx) {
      mx = vals[i][1];
      mx_index = i;
    }
  }
  pr(-1);
}
