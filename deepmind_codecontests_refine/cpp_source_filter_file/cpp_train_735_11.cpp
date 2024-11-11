#include <bits/stdc++.h>
using LL = long long;
using ULL = unsigned long long;
using std::cin;
using std::cout;
using std::endl;
using INT_PUT = int;
INT_PUT readIn() {
  INT_PUT a = 0;
  bool positive = true;
  char ch = getchar();
  while (!(ch == '-' || std::isdigit(ch))) ch = getchar();
  if (ch == '-') {
    positive = false;
    ch = getchar();
  }
  while (std::isdigit(ch)) {
    a = a * 10 - (ch - '0');
    ch = getchar();
  }
  return positive ? -a : a;
}
void printOut(INT_PUT x) {
  char buffer[20];
  int length = 0;
  if (x < 0)
    putchar('-');
  else
    x = -x;
  do buffer[length++] = -(x % 10) + '0';
  while (x /= 10);
  do putchar(buffer[--length]);
  while (length);
  putchar('\n');
}
const int maxn = int(1e5);
std::vector<std::vector<int>> vec(maxn + 1);
void init() {
  vec[1].push_back(1);
  for (int i = 2; i <= maxn; i++) {
    auto& v = vec[i];
    for (int j = 1; j * j <= i; j++) {
      if (!(i % j)) {
        v.push_back(j);
        v.push_back(i / j);
      }
    }
    std::sort(v.begin(), v.end());
    v.resize(std::unique(v.begin(), v.end()) - v.begin());
  }
}
int Gcd(int a, int b) { return !b ? a : Gcd(b, a % b); }
int a[6][3];
int ans;
struct Node {
  int val;
  int type;
  Node() {}
  Node(int val, int type) : val(val), type(type) {}
  bool operator<(const Node& b) const {
    if (val != b.val) return val < b.val;
    return type < b.type;
  }
  bool operator==(const Node& b) const { return val == b.val; }
};
std::vector<Node> all;
int CountAll() {
  auto t = all;
  return std::unique(t.begin(), t.end()) - t.begin();
}
struct Triple {
  int a, b, c;
  bool operator<(const Triple& y) const {
    if (a != y.a) return a < y.a;
    if (b != y.b) return b < y.b;
    return c < y.c;
  }
  Triple() {}
  Triple(int a, int b, int c) : a(a), b(b), c(c) {}
};
std::map<Triple, int> map;
void run() {
  init();
  int T = readIn();
  while (T--) {
    for (int i = 0; i < 3; i++) a[0][i] = readIn();
    std::sort(a[0], a[0] + 3);
    auto triple = Triple(a[0][0], a[0][1], a[0][2]);
    if (map.count(triple)) {
      printOut(map[triple]);
      continue;
    }
    int idx[3] = {0, 1, 2};
    for (int i = 1; i < 6; i++) {
      std::next_permutation(idx, idx + 3);
      for (int j = 0; j < 3; j++) a[i][j] = a[0][idx[j]];
    }
    int ans = 0;
    int U = 1 << 6;
    for (int S = 1; S < U; S++) {
      int gcd[3]{};
      int sig = -1;
      for (int i = 0; i < 6; i++)
        if (S & (1 << i)) {
          sig = -sig;
          for (int j = 0; j < 3; j++) gcd[j] = Gcd(a[i][j], gcd[j]);
        }
      ans += vec[gcd[0]].size() * vec[gcd[1]].size() * vec[gcd[2]].size() * sig;
    }
    const auto& vx = vec[a[0][0]];
    const auto& vy = vec[a[0][1]];
    const auto& vz = vec[a[0][2]];
    all.clear();
    int i = 0, j = 0, k = 0;
    while (i < vx.size() || j < vy.size() || k < vz.size())
      if ((j >= vy.size() || (i < vx.size() && vx[i] <= vy[j])) &&
          (k >= vz.size() || (i < vx.size() && vx[i] <= vz[k])))
        all.push_back(Node(vx[i++], 0));
      else if (k >= vz.size() || (j < vy.size() && vy[j] <= vz[k]))
        all.push_back(Node(vy[j++], 0));
      else
        all.push_back(Node(vz[k++], 2));
    int countAll = CountAll();
    int same3 = 0;
    int pre2 = -1, pre1 = -1;
    for (const auto& t : all) {
      if (pre1 == pre2 && t.val == pre1) same3++;
      pre2 = pre1;
      pre1 = t.val;
    }
    int count_ = 1;
    int same2 = 0;
    for (i = 1; i < all.size(); i++) {
      if (all[i].val == all[i - 1].val) count_++;
      if (all[i].val != all[i - 1].val || i == all.size() - 1) {
        if (count_ == 2) {
          int appear[3]{};
          if (all[i].val != all[i - 1].val)
            for (int j = 1; j <= 2; j++) appear[all[i - j].type]++;
          else
            for (int j = 0; j < 2; j++) appear[all[i - j].type]++;
          if (!appear[0])
            same2 += vx.size();
          else if (!appear[1])
            same2 += vy.size();
          else if (!appear[2])
            same2 += vz.size();
        } else if (count_ == 3)
          same2 += countAll - 1;
        count_ = 1;
      }
    }
    printOut(map[triple] = (ans + same2 * 3 + same3 * 5) / 6);
  }
}
int main() {
  run();
  return 0;
}
