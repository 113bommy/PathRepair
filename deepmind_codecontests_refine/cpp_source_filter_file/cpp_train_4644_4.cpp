#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) {
  return n | (1LL << i);
  ;
}
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long &a) {
  a %= 1000000007;
  (a < 0) && (a += 1000000007);
}
inline long long modMul(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a * b) % 1000000007;
}
inline long long modAdd(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a + b) % 1000000007;
}
inline long long modSub(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, 1000000007 - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
vector<vector<int> > tree;
int cnt[501000];
void insert(int num, int val) {
  int cur_node = 0;
  cnt[cur_node] += val;
  for (int i = 2; i >= 0; --i) {
    if (tree[cur_node][checkBit(num, i)] == -1) {
      vector<int> temp(2, -1);
      tree.emplace_back(temp);
      tree[cur_node][checkBit(num, i)] = tree.size() - 1;
    }
    cur_node = tree[cur_node][checkBit(num, i)];
    cnt[cur_node] += val;
  }
}
int query(int val, int lol) {
  int cur_node = 0, ans = 0;
  ;
  for (int i = 2; i >= 0 && cur_node != -1; --i) {
    ;
    int valb = checkBit(val, i), lolb = checkBit(lol, i);
    ;
    if (i == 0) {
      if (lolb == 1) {
        if (tree[cur_node][0] != -1) ans += cnt[tree[cur_node][0]];
        if (tree[cur_node][1] != -1) ans += cnt[tree[cur_node][1]];
      } else if (lolb == 0) {
        if (tree[cur_node][valb] != -1) ans += cnt[tree[cur_node][valb]];
      }
      continue;
    }
    if (lolb == 1) {
      if (valb == 0) {
        if (tree[cur_node][0] != -1) ans += cnt[tree[cur_node][0]];
        cur_node = tree[cur_node][1];
      } else {
        if (tree[cur_node][1] != -1) ans += cnt[tree[cur_node][1]];
        cur_node = tree[cur_node][0];
      }
    } else if (lolb == 0) {
      if (valb == 0) {
        cur_node = tree[cur_node][0];
      } else {
        cur_node = tree[cur_node][1];
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  tree.push_back(vector<int>{-1, -1});
  int q;
  cin >> q;
  while (q--) {
    int d, r;
    cin >> d >> r;
    if (d == 1) {
      insert(r, 1);
    } else if (d == 2) {
      insert(r, -1);
    } else if (d == 3) {
      int l;
      cin >> l;
      --l;
      cout << query(r, l) << '\n';
    };
  }
  return 0;
}
