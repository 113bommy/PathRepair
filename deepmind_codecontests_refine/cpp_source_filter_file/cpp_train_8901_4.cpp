#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &o, vector<T> v) {
  if (v.size() > 0) o << v[0];
  for (unsigned i = 1; i < v.size(); i++) o << " " << v[i];
  return o << endl;
}
template <typename U, typename V>
ostream &operator<<(ostream &o, pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ") ";
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (unsigned i = 0; i < v.size(); i++) in >> v[i];
  return in;
}
vector<int> segs = {6, 2, 5, 5, 4, 5, 6, 4, 7, 6};
int countSegs(int n) {
  if (n == 0) return segs[0];
  int cnt = 0;
  while (n > 0) {
    cnt += segs[n % 10];
    n /= 10;
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  long long cnt = 0;
  for (int(i) = (int)(a); (i) < (int)(b + 1); ++(i)) {
    cnt += countSegs(i);
  }
  cout << cnt << endl;
}
