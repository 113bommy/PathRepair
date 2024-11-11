#include <bits/stdc++.h>
using namespace std;
void boostIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
template <typename T>
T getint() {
  T val = 0;
  char c;
  bool neg = false;
  while ((c = getchar()) && !(c >= '0' && c <= '9')) {
    neg |= c == '-';
  }
  do {
    val = (val * 10) + c - '0';
  } while ((c = getchar()) && (c >= '0' && c <= '9'));
  return val * (neg ? -1 : 1);
}
const double eps = 1e-7;
bool ls(double first, double second) { return second - first > eps; }
bool eq(double first, double second) { return abs(first - second) < eps; }
bool lsoreq(double first, double second) {
  return ls(first, second) || eq(first, second);
}
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
const int inf = 1e9 + 7;
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
int n;
vector<int> ask[13];
int a[maxn];
long long ans[maxn];
int main() {
  boostIO();
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < (1 << 13) && cnt < n; ++i) {
    int sz = 0;
    for (int j = 0; j < 13; ++j)
      if (i & (1 << j)) ++sz;
    if (sz != 6) continue;
    a[cnt++] = i;
    for (int j = 0; j < 13; ++j)
      if (i & (1 << j)) ask[j].push_back(cnt);
  }
  for (int i = 0; i < 13; ++i) {
    if (ask[i].size() == 0) continue;
    cout << "? " << ask[i].size() << ' ';
    for (int j : ask[i]) cout << j << ' ';
    cout << endl;
    cin >> ans[i];
  }
  cout << "! ";
  for (int i = 0; i < n; ++i) {
    int b = 0;
    for (int j = 0; j < 13; ++j)
      if (!(a[i] & (1 << j))) b |= ans[j];
    cout << b << ' ';
  }
  cout << endl;
  return 0;
}
