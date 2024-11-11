#include <bits/stdc++.h>
using namespace std;
const long maxn = 7;
const long inf = 100000000;
struct elem {
  long lower;
  long upper;
  long act;
};
elem edge[maxn][maxn];
long n, si, fi;
long howmany[maxn];
inline long solve(long ver, long step, long sum) {
  if (ver == n) return (0);
  if (sum > howmany[ver]) return (-inf);
  if (step == n + 1)
    if (sum == howmany[ver])
      return (solve(ver + 1, ver + 2, 0));
    else
      return (-inf);
  long maxx = -inf;
  for (long j = edge[ver][step].lower; j <= edge[ver][step].upper; j++) {
    howmany[step] += j;
    long bonus;
    if (j == 0)
      bonus = 0;
    else
      bonus = j * j + edge[ver][step].act;
    maxx = max(bonus + solve(ver, step + 1, sum + j), maxx);
    howmany[step] -= j;
  }
  return (maxx);
}
int main() {
  scanf("%ld", &n);
  for (long q = 1; q <= n * (n - 1) / 2; q++) {
    scanf("%ld%ld", &si, &fi);
    scanf("%ld%ld%ld", &edge[si][fi].lower, &edge[si][fi].upper,
          &edge[si][fi].act);
  }
  bool f = false;
  for (long choice = 0; choice <= 30; choice++) {
    howmany[1] = choice;
    long temp = solve(1, 2, 0);
    if (temp >= 0) {
      f = true;
      printf("%ld %ld", choice, temp);
      break;
    }
  }
  if (f == false) printf("-1 -1");
}
