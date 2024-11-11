#include <bits/stdc++.h>
using namespace std;
ofstream file("debug.txt");
template <typename Int>
ostream &operator<<(ostream &s, const vector<Int> &v) {
  s << '[';
  for (auto i = v.begin(); i != v.end(); i++) {
    s << *i;
    if (i != prev(v.end())) s << ", ";
  }
  s << ']';
  return s;
}
template <typename Int, typename INT>
ostream &operator<<(ostream &s, const map<Int, INT> &mp) {
  s << '[';
  for (auto &i : mp) {
    s << '[' << i.first << ", " << i.second << ']';
    if (i != *mp.rbegin()) s << ", ";
  }
  s << ']';
  return s;
}
template <typename Int>
ostream &operator<<(ostream &s, const set<Int> &st) {
  s << '[';
  for (auto &i : st) {
    s << i;
    if (i != *st.rbegin()) s << ", ";
  }
  s << ']';
  s << '\n';
  return s;
}
template <typename Int, typename INt>
ostream &operator<<(ostream &s, const pair<Int, INt> &x) {
  s << '[' << x.first << ", " << x.second << ']';
  return s;
}
template <typename T>
void print(T *x, int n) {
  for (int i = 0; i < n; i++) {
    file << x[i] << " \n"[i == n - 1];
  }
}
template <typename T>
ostream &operator<<(ostream &s, const complex<T> &a) {
  s << '(' << a.real() << ", " << a.imag() << ')';
  return s;
}
const int N = 1000 + 5;
int n, m, h, x[N], sum;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> h;
  h--;
  for (int i = 0; i < m; i++) {
    cin >> x[i];
    if (i != h) sum += x[i];
  }
  x[h]--;
  n--;
  if (sum + x[h] < n)
    cout << -1;
  else {
    double ans = 1;
    for (int i = 0; i < n; i++) ans = ans * (sum - i) / (sum + x[h] - i);
    cout << fixed << setprecision(9) << 1 - ans;
  }
}
