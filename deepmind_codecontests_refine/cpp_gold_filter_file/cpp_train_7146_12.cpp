#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
struct node_ {
  int v;
  int idx;
} node[maxN];
bool cmp(node_ a, node_ b) {
  if (a.v == b.v)
    return a.idx < b.idx;
  else
    return a.v < b.v;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
vector<int> va[maxN];
void bfs(int now, int p) {
  vector<int> tnode = va[now];
  if (tnode.size() == 0) {
    return;
  }
  for (int i = 0; i < tnode.size(); i++) {
    bfs(tnode[i], now);
  }
}
int getDigit(int n) {
  int tmp = 1;
  while (n) {
    if (n % 10 != 0) tmp *= n % 10;
    n = n / 10;
  }
  return tmp;
}
vector<int> primes;
void init_primes(int n) {
  primes.push_back(2), primes.push_back(3), primes.push_back(5);
  for (int i = primes.back() + 2; i <= n; i += 2) {
    bool flag = true;
    for (int j = 0; j < primes.size(); ++j) {
      int p = primes[j];
      if (p * p > i) break;
      if (i % p == 0) {
        flag = false;
        break;
      }
    }
    if (flag) primes.push_back(i);
  }
}
bool is_prime(int n) {
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0 || n <= 1) return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}
double distance(double x1, double y1, double x2, double y2,
                bool precise = false) {
  if (precise) return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
  int x, y, z, ans;
  char str[maxN], str2[maxN * 2];
  int m, n, k, tmp, v_[3], vv[3], cnt, p;
  double x1, y1, x2, y2, r;
  double xa, ya, ra;
  while (scanf("%lf%lf%lf%lf%lf", &r, &x1, &y1, &x2, &y2) != EOF) {
    if (distance(x1, y1, x2, y2, true) < r * r) {
      if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) < 1e-13) {
        ra = r / 2;
        xa = x1 + r / 2;
        ya = y1;
      } else {
        ra = (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) + r) / 2;
        xa = x2 + ra * (x1 - x2) /
                      sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        ya = y2 + ra * (y1 - y2) /
                      sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
      }
      printf("%.8f %.8f %.8f\n", xa, ya, ra);
    } else {
      printf("%.8f %.8f %.8f\n", x1, y1, r);
    }
  }
  return 0;
}
