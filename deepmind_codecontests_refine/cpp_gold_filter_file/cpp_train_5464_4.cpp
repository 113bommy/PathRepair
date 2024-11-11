#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Read(T &x) {
  char ch;
  bool neg = 0;
  x = 0;
  while (!isdigit(ch = getchar()) && ch != '-')
    ;
  if (ch == '-') {
    neg = 1;
    ch = getchar();
  }
  do {
    x = x * 10 + ch - 48;
  } while (isdigit(ch = getchar()));
  if (neg) x = -x;
  return;
}
template <typename T>
void Write(T x) {
  char ch[32];
  int cnt = 0;
  bool neg = 0;
  if (x < 0) {
    neg = 1;
    x = -x;
  }
  do {
    ch[++cnt] = x % 10 + 48;
    x /= 10;
  } while (x);
  if (neg) putchar('-');
  for (int i = (cnt); i >= (1); --i) putchar(ch[i]);
}
template <typename T>
void Writeln(T x) {
  Write(x);
  putchar('\n');
}
template <typename T>
void Writesp(T x) {
  Write(x);
  putchar(' ');
}
const int MAX = 2e5 + 5;
int n;
int a[MAX], pos[MAX];
int64_t num[MAX];
map<int, int> mp;
struct Fenwick {
  int64_t Tree[MAX];
  void Init() { memset(Tree, 0, sizeof Tree); }
  void Update(int u, int val) {
    for (int i = u; i <= n; i += i & -i) Tree[i] += val;
  }
  int64_t Query(int u) {
    int64_t ans = 0;
    for (int i = u; i > 0; i -= i & -i) ans += Tree[i];
    return ans;
  }
} BIT;
int GetIndex(int val) {
  int l = 1, r = n, mid, ans;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (pos[mid] <= val) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ans;
}
void Enter() {
  int u, v;
  vector<int> Arr;
  vector<pair<int, int> > q;
  Read(n);
  for (int i = (1); i <= (n); ++i) {
    Read(u);
    Read(v);
    q.push_back(pair<int, int>(u, v));
    Arr.push_back(u);
    Arr.push_back(v);
  }
  sort((Arr).begin(), (Arr).end());
  Arr.resize(unique(Arr.begin(), Arr.end()) - Arr.begin());
  n = Arr.size();
  for (int i = 0; i < (Arr).size(); ++i) {
    a[i + 1] = Arr[i];
    pos[i + 1] = Arr[i];
  }
  for (int i = 0; i < (q).size(); ++i) {
    int id0 = GetIndex(q[i].first), id1 = GetIndex(q[i].second);
    swap(a[id0], a[id1]);
  }
}
void Solve() {
  for (int i = (1); i <= (n); ++i) {
    int index = GetIndex(a[i]);
    num[i] = 0;
    if (index < i)
      num[i] = pos[i] - a[i] - i + index;
    else
      num[i] = a[i] - pos[i] - index + i;
  }
  int64_t res = 0;
  for (int i = (n); i >= (1); --i) {
    res += BIT.Query(GetIndex(a[i]) - 1);
    res += num[i];
    BIT.Update(GetIndex(a[i]), 1);
  }
  Write(res);
}
int main(int argc, char const *argv[]) {
  Enter();
  Solve();
  return 0;
}
