#include <bits/stdc++.h>
using namespace std;
long long n, dsu[11000000], temp, maxnum;
bool used[11000000], exist[11000000];
long long get(long long v) { return (dsu[v] == v) ? v : dsu[v] = get(dsu[v]); }
void unite(long long x, long long y) {
  long long a = get(x), b = get(y);
  if (rand() & 1) swap(a, b);
  dsu[a] = b;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  srand(time(NULL));
  scanf("%d", &n);
  memset(exist, 0, sizeof(exist));
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp), exist[temp] = true;
    maxnum = max(maxnum, temp);
  }
  for (int i = 1; i <= maxnum; i++) dsu[i] = i;
  for (long long x = 1; x <= 1.5 * sqrt(maxnum + 0.0); x++) {
    for (long long y = 1; y <= 0.5 * sqrt(maxnum + 0.0); y++) {
      long long first = x * x - y * y, second = 2 * x * y,
                third = x * x + y * y;
      if (first <= 0 || second <= 0 || third <= 0) continue;
      if (gcd(gcd(first, second), third) != 1) continue;
      if (first <= maxnum && second <= maxnum && exist[first] && exist[second])
        unite(first, second);
      if (second <= maxnum && third <= maxnum && exist[second] && exist[third])
        unite(second, third);
      if (first <= maxnum && third <= maxnum && exist[first] && exist[third])
        unite(first, third);
    }
  }
  int answer = 0;
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= maxnum; i++)
    if (exist[i] && !used[get(i)]) answer++, used[get(i)] = true;
  printf("%d", answer);
  return 0;
}
