#include <bits/stdc++.h>
using namespace std;
long long prime[10000001] = {0};
int GCD(int A, int B) {
  int m = min(A, B), gcd;
  for (int i = m; i > 0; --i)
    if (A % i == 0 && B % i == 0) {
      gcd = i;
      return gcd;
    }
}
long long count_one(long long n) {
  long long count1 = 0;
  while (n) {
    n = n & (n - 1);
    count1++;
  }
  return count1;
}
std::vector<long long> v;
long long n, m;
long long check(long long x) {
  long long j = 0;
  long long sum1 = 0;
  while (1) {
    if (v[j] - (j / x) <= 0) {
      break;
    }
    sum1 = sum1 + v[j] - (j / x);
    j++;
    if (j == n) break;
  }
  if (sum1 >= m) {
    return 1;
  } else {
    return 0;
  }
}
long long bs(long long l, long long h) {
  while (h > l) {
    long long mid = l + (h - l) / 2;
    long long x = check(mid);
    if (x == 1) {
      h = mid;
    } else {
      l = mid + 1;
    }
  }
  return h;
}
int main() {
  cin >> n >> m;
  if (n > (m * m - 1)) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  queue<pair<long long, long long> > q;
  long long i = 0, j = 1, count1 = 0;
  for (long long e = 0; e < m; e++) {
    q.push(make_pair(i, j));
    i = (i + 1) % (m);
    j = (j + 1) % (m);
  }
  while (1) {
    pair<long long, long long> p = q.front();
    q.pop();
    if (p.first != p.second) {
      printf("%lld %lld\n", p.first + 1, p.second + 1);
      count1++;
    }
    long long y = (p.second + 1) % (m);
    q.push(make_pair(p.first, y));
    if (count1 == n) break;
  }
}
