#include <bits/stdc++.h>
using namespace std;
void readi(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readll(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline long long inc(int &x) { return ++x; }
inline long long inc(long long &x) { return ++x; }
inline long long inc(int &x, long long y) { return x += y; }
inline long long inc(long long &x, long long y) { return x += y; }
inline double inc(double &x, double y) { return x += y; }
inline long long dec(int &x) { return --x; }
inline long long dec(long long &x) { return --x; }
inline long long dec(int &x, long long y) { return x -= y; }
inline long long dec(long long &x, long long y) { return x -= y; }
inline double dec(double &x, double y) { return x -= y; }
inline long long mul(int &x) { return x = ((long long)x) * x; }
inline long long mul(long long &x) { return x = x * x; }
inline long long mul(int &x, long long y) { return x *= y; }
inline long long mul(long long &x, long long y) { return x *= y; }
inline double mul(double &x, double y) { return x *= y; }
inline long long divi(int &x) { return x = sqrt(x); }
inline long long divi(long long &x) { return x = sqrt(x); }
inline long long divi(int &x, long long y) { return x /= y; }
inline long long divi(long long &x, long long y) { return x /= y; }
inline double divi(double &x, double y) { return x /= y; }
inline long long mod(int &x, long long y) { return x %= y; }
inline long long mod(long long &x, long long y) { return x %= y; }
long long n, m, i, j, ans, x, y, lst = 0, fa[100005];
struct ed {
  long long x, y, z;
};
vector<ed> e;
vector<pair<long long, char> > seq;
long long find(long long x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
bool cmp(ed x, ed y) { return x.z < y.z; }
long long gt(long long l, long long r) {
  long long ans = (seq[r].first - seq[l].first) * 2,
            ans2 = seq[r].first - seq[l].first;
  if (l == 0 || r == n + 1) ans2 = 0;
  e.clear();
  long long lstb = -1, lstr = -1, i;
  fa[find(l)] = r;
  for (i = l + 1; i < r; i++) {
    if (seq[i].second == 'B') {
      if (lstb != -1) {
        e.push_back((ed){lstb, i, seq[i].first - seq[lstb].first});
      }
      lstb = i;
    } else {
      if (lstb != -1) {
        e.push_back((ed){lstr, i, seq[i].first - seq[lstr].first});
      }
      lstr = i;
    }
    if (l != 0) e.push_back((ed){l, i, seq[i].first - seq[l].first});
    if (r != n + 1) e.push_back((ed){r, i, seq[r].first - seq[i].first});
  }
  stable_sort((e).begin(), (e).end(), cmp);
  for (i = 0; i < e.size(); i++) {
    if (find(e[i].x) != find(e[i].y)) {
      fa[find(e[i].x)] = find(e[i].y);
      ans2 += e[i].z;
    }
  }
  return min(ans, ans2);
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin >> n;
  seq.push_back(make_pair(-0x1bbbbbbbbbbbbbbbll, 'P'));
  seq.push_back(make_pair(0x1bbbbbbbbbbbbbbbll, 'P'));
  if ((1) <= ((n)))
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
      fa[i] = i;
      char c;
      cin >> x >> c;
      seq.push_back(make_pair(x, c));
    }
  fa[n + 1] = n + 1;
  stable_sort((seq).begin(), (seq).end());
  for (i = 1; i < seq.size(); i++) {
    if (seq[i].second == 'P') {
      ans += gt(lst, i);
      lst = i;
    }
  }
  cout << ans;
  return 0;
}
