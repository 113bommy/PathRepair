#include <bits/stdc++.h>
using namespace std;
inline int Lowbit(int i) { return i & (-i); }
inline void read(int &n) {
  char c;
  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
    ;
  n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int main() {
  int N, x, a, b;
  ios ::sync_with_stdio(false);
  cin >> N >> x >> a >> b;
  for (int i = 1; i < N; ++i) {
    cin >> a >> b;
    if (a == x || a == 7 - a || b == x || b == 7 - x) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
