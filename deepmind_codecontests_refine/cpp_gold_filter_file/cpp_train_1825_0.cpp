#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
const long long INFll = 1ll * INF * INF;
const long double ldINF = 1e+018;
const long double EPS = 0.000000001;
const int N = 100001;
template <typename T>
ostream& operator<<(ostream& out, pair<T, T>& a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T>
istream& operator>>(istream& in, pair<T, T>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<pair<T, T> > a) {
  for (int i = 0; i < a.size(); ++i) out << a[i] << endl;
  return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> a) {
  for (int i = 0; i < a.size(); ++i)
    if (i == a.size() - 1)
      out << a[i];
    else
      out << a[i] << " ";
  return out;
}
void compress(vector<pair<long long, string> >& a) {
  vector<pair<long long, string> > res;
  res.push_back(a[0]);
  for (int i = 1; i < a.size(); i++)
    if (a[i].second == a[i - 1].second)
      res.back().first += a[i].first;
    else
      res.push_back(a[i]);
  a = res;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int z = n;
  vector<pair<long long, string> > a(n), b(m);
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    int num = 0;
    int x = 0;
    for (int j = 0; j < t.size(); j++)
      if (t[j] < '0' || t[j] > '9') {
        num = j;
        break;
      } else
        x = x * 10 + (t[j] - '0');
    string y = "";
    y = t.substr(num + 1, t.size() - num - 1);
    a[i] = make_pair(x, y);
  }
  for (int i = 0; i < m; i++) {
    string t;
    cin >> t;
    int num = 0;
    int x = 0;
    for (int j = 0; j < t.size(); j++)
      if (t[j] < '0' || t[j] > '9') {
        num = j;
        break;
      } else
        x = x * 10 + (t[j] - '0');
    string y = "";
    y = t.substr(num + 1, t.size() - num - 1);
    b[i] = make_pair(x, y);
  }
  compress(a);
  compress(b);
  n = a.size(), m = b.size();
  if (m == 1) {
    long long ans = 0;
    for (int i = 0; i < n; i++)
      if (a[i].second == b[0].second && a[i].first >= b[0].first)
        ans += (a[i].first - b[0].first + 1);
    cout << ans << endl;
    return 0;
  }
  if (m == 2) {
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
      if (a[i].second == b[0].second && a[i + 1].second == b[1].second &&
          a[i].first >= b[0].first && a[i + 1].first >= b[1].first)
        ans++;
    cout << ans << endl;
    return 0;
  }
  vector<pair<long long, string> > s;
  for (int i = 1; i < m - 1; i++) s.push_back(b[i]);
  s.push_back(make_pair(-1, "#"));
  for (int i = 0; i < a.size(); i++) s.push_back(a[i]);
  vector<int> p(s.size(), 0);
  for (int i = 1; i < s.size(); i++) {
    int j = p[i - 1];
    while (j > 0 && s[i] != s[j]) j = p[j - 1];
    if (s[i] == s[j]) j++;
    p[i] = j;
  }
  int ans = 0;
  int len = m - 2;
  for (int i = 0; i < s.size(); i++)
    if (p[i] == len) {
      int l = i - 2 * len - 1;
      int r = l + len + 1;
      if (l < 0 || r >= n) continue;
      if (a[l].second == b[0].second && a[l].first >= b[0].first &&
          a[r].second == b.back().second && a[r].first >= b.back().first)
        ans++;
    }
  cout << ans << endl;
  if (0)
    cerr << fixed << setprecision(0)
         << "TIME = " << clock() / (long double)CLOCKS_PER_SEC * 1000 << "\n";
  return 0;
}
