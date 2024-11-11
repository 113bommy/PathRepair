#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <class T>
ostream& prnt(ostream& out, T v) {
  out << v.size() << '\n';
  for (auto e : v) out << e << ' ';
  return out;
}
template <class T>
ostream& operator<<(ostream& out, vector<T> v) {
  return prnt(out, v);
}
template <class T>
ostream& operator<<(ostream& out, set<T> v) {
  return prnt(out, v);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, map<T1, T2> v) {
  return prnt(out, v);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  return out << '(' << p.first << ' ' << p.second << ')';
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
int n, m, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  if (k + m >= n)
    puts("Yes");
  else
    puts("No");
}
