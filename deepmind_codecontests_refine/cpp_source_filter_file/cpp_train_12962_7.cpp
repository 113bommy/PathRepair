#include <bits/stdc++.h>
using namespace std;
const int N = 1001000, P1 = 1000000007, P2 = 1000000009;
int i, j, k, n, m, t1, t2, o1, o2;
int tm1[N], tm2[N];
char s1[N], s2[N];
char get(char x) {
  if (x == 'W') return 'E';
  if (x == 'E') return 'W';
  if (x == 'S') return 'N';
  if (x == 'N') return 'S';
}
int main() {
  scanf("%d", &n);
  n--;
  scanf("%s", s1 + 1);
  scanf("%s", s2 + 1);
  tm1[0] = tm2[0] = 1;
  for (i = 1; i <= n; i++)
    tm1[i] = 31ll * tm1[i] % P1, tm2[i] = 31ll * tm2[i] % P2;
  for (i = n; i; i--) {
    s2[i] = get(s2[i]);
    t1 = (31ll * t1 + s1[i]) % P1;
    t2 = (1ll * s2[i] * tm1[n - i] + t2) % P1;
    o1 = (31ll * o1 + s1[i]) % P2;
    o2 = (1ll * s2[i] * tm2[n - i] + o2) % P2;
    if (t1 == t2 && o1 == o2) return puts("NO"), 0;
  }
  puts("YES");
}
