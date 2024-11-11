#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
const int N = 300005;
int n, k, zs[N];
vector<pair<int, int> > v[N];
pair<long long, long long> check(int x) {
  long long ans1 = 0, ans2 = 0, tot = 0;
  int sum = 0, dq = 0;
  memset(zs, 0, sizeof(zs));
  for (int i = 1; i <= n; i++) {
    for (auto j : v[i]) {
      if (j.first <= dq) {
        sum += j.second;
        tot += (long long)(dq - j.first + 1) * j.second;
      } else {
        zs[j.first] += j.second;
      }
    }
    while (dq < i && sum + zs[dq + 1] >= x) {
      sum += zs[++dq];
      tot += sum;
    }
    ans1 += dq;
    ans2 += tot;
  }
  return make_pair(ans1, ans2);
}
struct data {
  int l, r, id;
};
bool operator<(data a, data b) { return a.l == b.l ? a.r < b.r : a.l < b.l; }
set<data> s;
void split(int pos) {
  auto it = s.lower_bound((data){pos, 0, 0});
  if (it != s.begin())
    it--;
  else
    return;
  if ((*it).l > pos || (*it).r < pos) return;
  s.insert((data){(*it).l, pos, (*it).id});
  s.insert((data){pos, (*it).r, (*it).id});
  s.erase(it);
}
void insert(int l, int r, int id) {
  for (auto it = s.lower_bound((data){l, 0, 0});
       it != s.end() && (*it).r <= r;) {
    v[id].push_back(make_pair((*it).id + 1, ((*it).r - (*it).l)));
    s.erase(it++);
  }
  v[id].push_back(make_pair(id + 1, l - r));
  s.insert((data){l, r, id});
}
signed main() {
  n = read();
  k = read();
  s.insert((data){1, 1000000000, 0});
  for (int i = 1; i <= n; i++) {
    int l = read(), r = read();
    split(l);
    split(r);
    insert(l, r, i);
  }
  int l = 0, r = 1e9;
  while (l < r) {
    int mid = (l + r) >> 1;
    mid++;
    if (check(mid).first >= k)
      l = mid;
    else
      r = mid - 1;
  }
  cout << check(l).second - (check(l).first - k) * l << endl;
}
