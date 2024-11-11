#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Pii = pair<int, int>;
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void read(int &x) {
  char ch;
  while (blank(ch = nc()))
    ;
  if (IOerror) return;
  for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9';
       x = (x << 1) + (x << 3) + ch - '0')
    ;
}
inline void read(long long &x) {
  char ch;
  while (blank(ch = nc()))
    ;
  if (IOerror) return;
  for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9';
       x = (x << 1) + (x << 3) + ch - '0')
    ;
}
};  // namespace fastIO
int cnt = 0;
string l, r, pr;
vector<int> ans;
map<string, int> mp;
map<pair<int, int>, int> mpi;
int code(string const &name) {
  if (!mp.count(name)) mp.insert(pair<string, int>(name, cnt++));
  return mp[name];
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  ;
  int n, a, b, k, f, cost, codel, coder;
  LL sum = 0;
  cin >> n >> a >> b >> k >> f;
  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    if (l == pr)
      cost = b;
    else
      cost = a;
    codel = code(l), coder = code(r);
    if (codel > coder) swap(codel, coder);
    if (!mpi.count(pair<int, int>(codel, coder)))
      mpi.insert(pair<pair<int, int>, int>(pair<int, int>(codel, coder), cost));
    else
      mpi[pair<int, int>(codel, coder)] += cost;
    pr = r;
  }
  for (auto it : mpi) ans.push_back(move(it.second));
  sort(ans.begin(), ans.end(),
       [](int const &a, int const &b) -> bool { return a > b; });
  for (int it : ans) {
    if (f < it && k)
      sum += f, --k;
    else
      sum += it;
  }
  printf("%I64d\n", sum);
  return 0;
}
