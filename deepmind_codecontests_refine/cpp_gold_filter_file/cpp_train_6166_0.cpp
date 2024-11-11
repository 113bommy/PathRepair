#include <bits/stdc++.h>
using namespace std;
string reverse(string str) {
  string ss = str;
  for (long long i = str.length() - 1, j = 0; i >= 0; i--, j++) ss[j] = str[i];
  return ss;
}
int main() {
  long long n, m, cnt = 0, y = 0, max = 0;
  string rr = "";
  cin >> n >> m;
  vector<string> v(n);
  list<string> l;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    v[i] = s;
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < n; i++) {
    for (long long j = 1; j < n; j++) {
      string sp = reverse(v[j]);
      if (v[i] == sp && i != j) {
        cnt = cnt + 2 * (v[i].length());
        l.push_back(v[i]);
        l.push_front(v[j]);
        v[i] = "neerav";
        v[j] = "neerav";
        y++;
        break;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    string g = reverse(v[i]);
    if (g == v[i]) {
      if (v[i].length() > max) {
        max = v[i].length();
        rr = v[i];
      }
    }
  }
  cnt = cnt + rr.length();
  long long pp = 0;
  cout << cnt << endl;
  for (auto x : l) {
    if (pp == y) cout << rr;
    cout << x;
    pp++;
  }
  if (y == 0) cout << rr;
  return 0;
}
