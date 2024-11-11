#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
const double EPS = 1e-10;
const double PI = acos(-1.0);
long long ary[200100];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int i, j, k;
  int n, m;
  cin >> n >> m;
  cin >> ary[0];
  for (i = 1; i < n; i++) {
    long long tmp;
    cin >> tmp;
    ary[i] = ary[i - 1] + tmp;
  }
  long long pre = 0;
  while (m--) {
    long long tmp;
    cin >> tmp;
    pre += tmp;
    int index = upper_bound(ary, ary + n, pre) - ary;
    if (index == n) {
      cout << n << endl;
      pre = 0;
      continue;
    }
    cout << n - index << endl;
  }
  return 0;
}
