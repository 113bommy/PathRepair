#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
template <typename T>
static inline void cmax(T& a, const T& b) {
  if (b > a) a = b;
}
template <typename T>
static inline void cmin(T& a, const T& b) {
  if (b < a) a = b;
}
const int maxn = 100005;
int trie[500000][26];
int dp0[500000];
int dp1[500000];
int top = 1;
void add(const char* str) {
  int now = 1;
  for (int i = 0; str[i]; ++i) {
    int id = str[i] - 'a';
    if (trie[now][id] == 0) trie[now][id] = ++top;
    now = trie[now][id];
  }
}
int dfs0(int now) {
  int find_lose = 0;
  for (int i = 0; i < 26; ++i)
    if (trie[now][i]) {
      int x = dfs0(trie[now][i]);
      if (x == 0) {
        find_lose = 1;
        break;
      }
    }
  if (find_lose) {
    return dp0[now] = 1;
  } else {
    return dp0[now] = 0;
  }
}
int dfs1(int now) {
  int find_lose = 0;
  int s = 0;
  for (int i = 0; i < 26; ++i)
    if (trie[now][i]) {
      int x = dfs1(trie[now][i]);
      if (x == 0) {
        find_lose = 1;
        break;
      }
      ++s;
    }
  if (s == 0) {
    return dp1[now] = 1;
  }
  if (find_lose) {
    return dp1[now] = 1;
  } else {
    return dp1[now] = 0;
  }
}
char data[maxn];
int main() {
  const int n = Rint(), k = Rint();
  for (int i = 0; i < n; ++i) {
    scanf("%s", data);
    add(data);
  }
  dfs0(1);
  dfs1(1);
  int first_always_win = dp0[1];
  int first_always_lose = dp1[1];
  if (first_always_win && first_always_lose) {
    puts("First");
  } else if (first_always_win && !first_always_lose) {
    if (k % 2 == 1)
      puts("First");
    else
      puts("Second");
  } else if (!first_always_win && first_always_lose) {
    if (k % 2 == 1)
      puts("Second");
    else
      puts("First");
  } else {
    puts("Second");
  }
  return 0;
}
