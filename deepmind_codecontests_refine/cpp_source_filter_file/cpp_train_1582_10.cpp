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
const int N = 16, M = 2003;
int sum, a[N], b[N], dq;
bitset<M> dp[1 << N | 2];
int main() {
  int n = read(), k = read();
  for (int i = (int)(0); i <= (int)(n - 1); i++) sum += (a[i] = read());
  dp[0][0] = 1;
  for (int i = (int)(0); i <= (int)((1 << n) - 1); i++) {
    for (int j = sum / k * k, o = sum / k; j; j -= k, o--)
      dp[i][o] = dp[i][o] | dp[i][j];
    for (int j = (int)(0); j <= (int)(n - 1); j++)
      if (!(i >> j & 1)) {
        dp[i | (1 << j)] |= dp[i] << a[j];
      }
  }
  if (!dp[(1 << n) - 1][1]) {
    puts("NO");
    return 0;
  } else
    puts("YES");
  int zt = (1 << n) - 1, su = 1;
  while (zt) {
    if (su * k <= sum && dp[zt][su * k]) {
      su *= k;
      dq++;
    } else {
      for (int i = (int)(0); i <= (int)(n - 1); i++)
        if (zt >> i & 1 && su >= a[i] && dp[zt ^ (1 << i)][su - a[i]]) {
          b[i] = dq;
          su -= a[i];
          zt ^= 1 << i;
          break;
        }
    }
  }
  priority_queue<pair<int, int> > q;
  for (int i = (int)(0); i <= (int)(n - 1); i++) q.push(make_pair(b[i], a[i]));
  while (q.size() > 1) {
    pair<int, int> a = q.top();
    q.pop();
    pair<int, int> b = q.top();
    q.pop();
    int x = a.first, y = a.second + b.second;
    cout << a.second << " " << b.second << endl;
    while (y % k == 0) {
      x++;
      y /= k;
    }
    q.push(make_pair(x, y));
  }
}
