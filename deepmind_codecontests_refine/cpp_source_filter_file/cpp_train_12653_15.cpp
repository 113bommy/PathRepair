#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
const long double E = 1e-10;
unsigned char ccc;
bool _minus = false;
template <typename T>
inline T sqr(T t) {
  return (t * t);
}
inline void read(long long &n) {
  n = 0;
  _minus = false;
  while (true) {
    ccc = getchar();
    if (ccc == ' ' || ccc == '\n') break;
    if (ccc == '-') {
      _minus = true;
      continue;
    }
    n = n * 10 + ccc - '0';
  }
  if (_minus) n *= -1;
}
inline void read(int &n) {
  n = 0;
  _minus = false;
  while (true) {
    ccc = getchar();
    if (ccc == ' ' || ccc == '\n') break;
    if (ccc == '-') {
      _minus = true;
      continue;
    }
    n = n * 10 + ccc - '0';
  }
  if (_minus) n *= -1;
}
char wwww[12];
int kkkk;
inline void write(long long y) {
  long long x = y;
  kkkk = 0;
  if (!x)
    ++kkkk, wwww[kkkk] = '0';
  else
    while (x) {
      ++kkkk;
      wwww[kkkk] = char(x % 10 + '0');
      x /= 10;
    }
  for (int i = kkkk; i >= 1; --i) putchar(wwww[i]);
  putchar(' ');
}
struct str {
  map<int, pair<int, int> > m;
  bool has(int val) { return m.find(val) != m.end(); }
  pair<int, int> get(int val) { return m[val]; }
  void set(int val, pair<int, int> res) { m[val] = res; }
  void del(int val) { m.erase(val); }
};
int operator&(pair<int, int> a, pair<int, int> b) {
  if (a.second < b.first || b.second < a.first) return 0;
  int ans = abs(max(a.first, b.first) - min(a.second, b.second)) + 1;
  return ans;
}
str t1, t2;
long long get(int val) {
  if (t1.has(val) && t2.has(val)) return t1.get(val) & t2.get(val);
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  srand(time(NULL));
  cout.precision(5);
  cout << fixed;
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long res = 0;
  long long ans = 0;
  stack<pair<int, int> > s1, s2;
  s1.push(make_pair(INT_MAX, -1));
  s2.push(make_pair(INT_MIN, -1));
  for (int i = 0; i < n; i++) {
    set<int> to_delete;
    set<int> to_add;
    int l1 = i;
    while (s1.top().first < a[i]) {
      l1 = s1.top().second;
      res -= get(s1.top().first);
      t1.del(s1.top().first);
      s1.pop();
    }
    if (s1.top().first != a[i]) {
      t1.set(a[i], make_pair(l1, i));
      s1.push(make_pair(a[i], l1));
      res += get(s1.top().first);
    }
    int l2 = i;
    while (s2.top().first > b[i]) {
      l2 = s2.top().second;
      res -= get(s2.top().first);
      t2.del(s2.top().first);
      s2.pop();
    }
    if (s2.top().first != b[i]) {
      t2.set(b[i], make_pair(l2, i));
      s2.push(make_pair(b[i], l2));
      res += get(s2.top().first);
    }
    ans += res;
  }
  cout << ans << "\n";
}
