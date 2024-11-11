#include <bits/stdc++.h>
using namespace std;
long long n, res = 10E17;
pair<long long, long long> start, finish, A[100007], Pos[100007];
long long F(long long x) {
  pair<long long, long long> v;
  v.first = start.first + Pos[n].first * x / n;
  v.first += Pos[x % n].first;
  v.second = start.second + Pos[n].second * x / n;
  v.second += Pos[x % n].second;
  return abs(finish.first - v.first) + abs(finish.second - v.second);
}
long long bin(long long L, long long R) {
  while (L < R) {
    long long tm = (L + R) / 2;
    long long u = F(tm);
    if (u <= tm)
      R = tm;
    else
      L = tm + 1;
  }
  return L;
}
int main() {
  long long x, y;
  scanf("%lld %lld\n", &start.first, &start.second);
  scanf("%lld %lld\n", &finish.first, &finish.second);
  scanf("%lld\n", &n);
  pair<long long, long long> cpos = start;
  Pos[0] = {0, 0};
  for (int i = 1; i <= n; i++) {
    char x;
    scanf("%c", &x);
    if (x == 'U') A[i].second++;
    if (x == 'D') A[i].second--;
    if (x == 'L') A[i].first--;
    if (x == 'R') A[i].first++;
    cpos.first += A[i].first;
    cpos.second += A[i].second;
    Pos[i].first = Pos[i - 1].first + A[i].first;
    Pos[i].second = Pos[i - 1].second + A[i].second;
  }
  long long k = bin(0, 10E17);
  if (k == 10E17)
    printf("-1\n");
  else
    printf("%lld\n", k);
}
