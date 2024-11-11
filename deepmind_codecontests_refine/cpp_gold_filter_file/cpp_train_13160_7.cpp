#include <bits/stdc++.h>
using namespace std;
int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx4[] = {1, 0, -1, 0};
int dy4[] = {0, 1, 0, -1};
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << " : " << arg1 << "\n";
  ;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <class A, class B>
ostream &operator<<(ostream &out, const pair<A, B> &a) {
  return out << "(" << a.first << "," << a.second << ")";
}
template <class A>
ostream &operator<<(ostream &out, const vector<A> &a) {
  for (const A &it : a) out << it << " ";
  return out;
}
template <class A, class B>
istream &operator>>(istream &in, pair<A, B> &a) {
  return in >> a.first >> a.second;
}
template <class A>
istream &operator>>(istream &in, vector<A> &a) {
  for (A &i : a) in >> i;
  return in;
}
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
bool compare(pair<int, int> p1, pair<int, int> p2) {
  return p1.second < p2.second;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort((v).begin(), (v).end());
  int i = 1;
  while (i < n) {
    if (v[i].first <= v[i - 1].first) {
      v[i].first = v[i - 1].first + 1;
    }
    i++;
  }
  sort((v).begin(), (v).end(), compare);
  for (int i = 0; i < n; i++) {
    cout << v[i].first << " ";
  }
  cout << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
