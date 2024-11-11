#include <bits/stdc++.h>
const long long max_N = 155;
long long n;
char s[max_N], t[max_N], tax[max_N];
long long read() {
  char c = getchar();
  long long ans = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) ans = ans * 10 + c - '0', c = getchar();
  return ans;
}
long long read_char() {
  char c = getchar();
  while (c != 'A' && c != 'B') c = getchar();
  return c - 'A';
}
void Write(long long x) {
  if (x < 10)
    putchar(x + '0');
  else
    Write(x / 10), putchar(x % 10 + '0');
}
long long min(long long x, long long y) { return x < y ? x : y; }
long long max(long long x, long long y) { return x > y ? x : y; }
void ask(std::string X) {
  std::cout << '?' << ' ';
  for (long long i = 0; i < X.size(); i++) std::cout << tax[X[i]];
  std::cout << std::endl;
  long long x, y;
  std::cin >> x;
  assert(x != -1);
  while (x--) {
    std::cin >> y;
    for (long long i = y; i < y + X.size(); i++) s[i] = X[i - y];
  }
}
void check() {
  for (long long i = 1; i <= n; i++)
    if (!s[i]) goto stop;
  return;
stop:
  std::cout << '?' << ' ';
  for (long long i = 1; i <= n; i++) std::cout << tax[t[i]];
  std::cout << std::endl;
  long long x, y;
  std::cin >> x;
  assert(x != -1);
  while (x--) {
    std::cin >> y;
    for (long long i = 1; i <= n; i++) s[i] = t[i];
  }
}
void work() {
  tax['a'] = 'C', tax['b'] = 'H', tax['c'] = 'O';
  std::cin >> n;
  memset(s, 0, sizeof(s));
  if (n == 4) {
    ask("aa"), ask("ab"), ask("ac"), ask("bc");
    if (!s[1] && !s[2] && !s[3] && !s[4]) {
      ask("bbb");
      if (s[2] == 'b') {
        if (!s[4]) s[4] = 'a';
        if (!s[1]) s[1] = 'c';
      } else {
        ask("ccc");
        if (s[2] == 'c') {
          if (!s[4]) {
            t[1] = t[2] = t[3] = 'c', t[4] = 'b', check();
            if (!s[4]) s[4] = 'a';
          }
        } else {
          t[1] = 'c', t[2] = 'b', t[3] = 'b', t[4] = 'a', check();
          t[1] = 'c', t[2] = 'c', t[3] = 'b', t[4] = 'b', check();
          if (!s[1]) s[1] = 'c', s[2] = 'c', s[3] = 'b', s[4] = 'a';
        }
      }
    } else {
      for (t[1] = 'a'; t[1] <= 'c'; t[1]++)
        for (t[2] = 'a'; t[2] <= 'c'; t[2]++)
          for (t[3] = 'a'; t[3] <= 'c'; t[3]++)
            for (t[4] = 'a'; t[4] <= 'c'; t[4]++) {
              bool flag = true;
              for (long long i = 1; i <= 4; i++)
                if (s[i] && s[i] != t[i]) flag = false;
              for (long long i = 1; i < 4; i++)
                if ((!s[i] || !s[i + 1]) &&
                    (t[i] == 'a' || (t[i] == 'b' && t[i + 1] == 'c')))
                  flag = false;
              if (flag) check();
            }
    }
  } else {
    ask("aa"), ask("ab"), ask("ac"), ask("bc"), ask("cb");
    for (long long i = 2; i < n; i++)
      if (!s[i] && s[i - 1]) s[i] = s[i - 1];
    long long cnt = 0;
    for (t[1] = 'a'; t[1] <= 'c'; t[1]++)
      for (t[n] = 'a'; t[n] <= 'c'; t[n]++) {
        if (s[1] && s[1] != t[1]) continue;
        if (s[n] && s[n] != t[n]) continue;
        if (t[1] == 'a' && !s[1]) continue;
        if (t[n] != 'a' && !s[n] && t[n] != t[n - 1]) continue;
        for (long long i = 2; i < n; i++) t[i] = s[i];
        for (long long i = 2; i < n; i++)
          if (!t[i] && t[i - 1]) t[i] = t[i - 1];
        if (++cnt < 4)
          check();
        else {
          bool flag = true;
          for (long long i = 1; i <= n; i++) flag &= !!s[i];
          if (!flag) memcpy(s + 1, t + 1, n);
        }
      }
  }
  std::cout << '!' << ' ';
  for (long long i = 1; i <= n; i++) std::cout << tax[s[i]];
  std::cout << std::endl, std::cin >> n;
  assert(n);
}
int main() {
  long long t;
  std::cin >> t;
  while (t--) work();
  return 0;
}
