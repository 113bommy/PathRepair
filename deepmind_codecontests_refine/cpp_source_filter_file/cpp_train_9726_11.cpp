#include <bits/stdc++.h>
using namespace std;
const int N = 111;
int n;
string a[N];
const uint64_t P = 100000000000000081UL;
const uint64_t Q = 100000000000000099UL;
set<uint64_t> sa[N];
struct S {
  bool win;
  int self_score, other_score;
  bool operator<(const S& o) const {
    if (win != o.win) return win;
    if (self_score != o.self_score) return self_score > o.self_score;
    return other_score > o.other_score;
  }
};
map<string, S> mem;
uint64_t gethash(const string& b) {
  uint64_t hash = 1;
  for (char y : b) hash = (hash * 26 + (y - 'a')) % P;
  return hash;
}
uint64_t gethash2(const string& b) {
  uint64_t hash = 1;
  for (char y : b) hash = (hash * 26 + (y - 'a')) % Q;
  return hash;
}
int getval(const string& b) {
  int res = 0;
  int mx = 0;
  for (char y : b) {
    res += y - 'a' + 1;
    mx = max(mx, y - 'a' + 1);
  }
  return res * mx;
}
S dfs(string b) {
  if (mem.count(b)) return mem[b];
  S s = {false, 0, 0};
  for (char x = 'a'; x <= 'z'; ++x) {
    string c = b + x;
    int num = 0;
    auto hash = gethash(c);
    auto hash2 = gethash2(c);
    auto val = getval(c);
    for (int i = 0; i < n; ++i) {
      if (sa[i].count(hash) && sa[i].count(hash2)) ++num;
    }
    if (num > 0) {
      S t = dfs(c);
      t.win = !t.win;
      swap(t.self_score, t.other_score);
      t.self_score += val + num;
      if (t < s) s = t;
    }
    c = x + b;
    num = 0;
    hash = gethash(c);
    hash2 = gethash2(c);
    val = getval(c);
    for (int i = 0; i < n; ++i) {
      if (sa[i].count(hash) && sa[i].count(hash2)) ++num;
    }
    if (num > 0) {
      S t = dfs(c);
      t.win = !t.win;
      swap(t.self_score, t.other_score);
      t.self_score += val + num;
      if (t < s) s = t;
    }
  }
  mem[b] = s;
  return s;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int x = 0; x < a[i].length(); ++x) {
      uint64_t hash = 1;
      for (int y = x; y < a[i].length(); ++y) {
        hash = (hash * 26 + (a[i][y] - 'a')) % P;
        sa[i].insert(hash);
      }
      hash = 1;
      for (int y = x; y < a[i].length(); ++y) {
        hash = (hash * 26 + (a[i][y] - 'a')) % Q;
        sa[i].insert(hash);
      }
    }
  }
  auto s = dfs("");
  puts(s.win ? "First" : "Second");
  printf("%d %d\n", s.self_score, s.other_score);
}
