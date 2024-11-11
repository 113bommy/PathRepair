#include <bits/stdc++.h>
using namespace std;
template <class T>
using vv = vector<vector<T>>;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &t) {
  os << "{";
  for (int(i) = 0; (i) < (t.size()); ++(i)) {
    os << t[i] << ",";
  }
  os << "}" << endl;
  return os;
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &t) {
  return os << "(" << t.first << "," << t.second << ")";
}
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  int n;
  cin >> n;
  vector<long long> v(n), d(n), p(n), rem(n, 1), re;
  for (int(i) = 0; (i) < (n); ++(i)) cin >> v[i] >> d[i] >> p[i];
  for (int(i) = 0; (i) < (n); ++(i)) {
    int f = 1;
    while (f) {
      f = 0;
      for (int(j) = 0; (j) < (n); ++(j))
        if (p[j] < 0 && rem[j]) {
          f = 1;
          rem[j] = 0;
          for (int(k) = 0; (k) < (n); ++(k))
            if (k > j) p[k] -= d[j];
        }
    }
    if (p[i] < 0) continue;
    re.push_back(i);
    rem[i] = 0;
    int dd = v[i];
    for (int(j) = 0; (j) < (n); ++(j)) {
      int k = i + j + 1;
      if (k >= n || dd <= 0) break;
      if (rem[k]) {
        p[k] -= dd;
        --dd;
      }
    }
  }
  cout << re.size() << endl;
  for (long long r : re) cout << r + 1 << " ";
  cout << endl;
  return 0;
}
