#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long M = (long long)1e9 + 7;
int Int() {
  int x;
  scanf("%d", &x);
  return x;
}
long long Long() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
void Char(char* ch) { scanf("%s", ch); }
template <typename t>
t abs(t a) {
  if (a >= 0) return a;
  return -a;
}
template <typename t>
t Range(vector<t> v, t x) {
  auto u = equal_range(v.begin(), v.end(), x);
  return u.second - u.first;
}
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " ";
  err(++it, args...);
}
vector<int> sq;
void pre() {
  int f = 0;
  while (1LL * f * f < M) {
    sq.push_back(f * f);
    f++;
  }
}
int main() {
  pre();
  int n = Int();
  vector<pair<int, int> > pos;
  for (int i = 1; i <= n; i++) {
    int x = Int();
    int v = lower_bound(sq.begin(), sq.end(), x) - sq.begin();
    int u = sq[v] - x;
    if (v != 0) {
      v--;
      u = min(u, x - sq[v]);
    }
    pos.push_back({u, x});
  }
  sort(pos.begin(), pos.end());
  int qs = 0;
  long long res = 0;
  for (int i = 0; i < (int)pos.size(); i++) {
    if (pos[i].first == 0) {
      if (qs == n / 2) {
        if (pos[i].second == 0) {
          res += 1LL * 2;
        } else
          res += 1LL;
      } else
        qs++;
    } else {
      if (qs != n / 2) {
        res = res + 1LL * pos[i].first;
        qs++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
