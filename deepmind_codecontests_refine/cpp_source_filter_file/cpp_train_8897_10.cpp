#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a) {
  return (out << "(" << a.first << "; " << a.second << ")");
}
template <typename T1>
ostream &operator<<(ostream &cout, vector<T1> &a) {
  if ((int)a.size() == 0) return (cout << "()");
  cout << "(" << a[0];
  for (int i = 1; i < (int)a.size(); i++) cout << "; " << a[i];
  cout << ")";
  return cout;
}
const int nmax = 1000 * 1000;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
const long double pi = acos(-1.0);
const long long infl = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
int n, m, t, h, mi, s, used[nmax], ans[nmax], answer[nmax];
char ccc;
vector<pair<int, int> > a;
int main() {
  cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    cin >> h >> ccc >> mi >> ccc >> s;
    mi += 60 * h;
    s += 60 * mi;
    a.push_back(make_pair(s, i));
  }
  sort(a.begin(), a.end());
  int l = 0, last = 0, top = 0, dif = 0;
  bool f = false;
  for (int i = 0; i < n; i++) {
    while (l < i && a[i].first >= a[l].first + t) {
      used[ans[l]]--;
      if (used[ans[l]] == 0) dif--;
      l++;
    }
    if (dif == m) {
      ans[i] = last;
      used[last]++;
      if (used[last] == 1) dif++;
    } else {
      ans[i] = top++;
      used[ans[i]]++;
      if (used[ans[i]] == 1) dif++;
      last = top;
    }
    if (dif == m) f = true;
  }
  if (!f)
    cout << "No solution\n";
  else {
    cout << top << endl;
    for (int i = 0; i < n; i++) answer[a[i].second] = ans[i];
    for (int i = 0; i < n; i++) cout << answer[i] + 1 << endl;
  }
}
