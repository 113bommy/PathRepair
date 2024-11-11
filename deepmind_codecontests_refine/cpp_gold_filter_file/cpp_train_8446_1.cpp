#include <bits/stdc++.h>
using namespace std;
inline long long find(string b, string a) {
  long long la = a.length();
  long long lb = b.length();
  for (long long i = 0; i < la; i++) {
    if (a[i] == b[0]) {
      long long j = 0;
      while (a[i + 1] == b[j + 1] && i < la && j < lb) i++, j++;
      if (j == lb && i == la) return 1;
    }
  }
  return 0;
}
inline long long check(string s) {
  long long l = s.length();
  if (find("lios", s)) return 1;
  if (find("liala", s)) return -1;
  if (find("etr", s)) return 2;
  if (find("etra", s)) return -2;
  if (find("inites", s)) return -3;
  if (find("initis", s)) return 3;
  return 0;
}
vector<long long> v;
signed main() {
  ios::sync_with_stdio(0);
  long long f = 1, f1, f2, f3;
  f1 = f2 = f3 = 0;
  string s;
  long long cnt = 0;
  long long sex = 0;
  while (cin >> s) {
    long long x = check(s);
    if (!x) {
      cout << "NO";
      return 0;
    }
    v.push_back(x);
  }
  for (auto i : v) {
    if (abs(i) == 2) cnt++;
  }
  if (v.size() == 1 && f) {
    cout << "YES";
    return 0;
  }
  if (cnt != 1) f = 0;
  for (long long i = 1; i < v.size(); i++)
    if (abs(v[i]) < abs(v[i - 1])) f = 0;
  sort(v.begin(), v.end());
  if (v[0] < 0 && v[v.size() - 1] > 0) f = 0;
  if (v[0] > 0 && v[v.size() - 1] < 0) f = 0;
  if (f)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
