#include <bits/stdc++.h>
const long long m = 1000000007;
using namespace std;
void sc(int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 != 0) res = (res * a) % m;
    a = (a * a) % m;
    b /= 2;
  }
  return res % m;
}
long long gcd(long long a, long long b) {
  return ((b == 0) ? a : gcd(b, a % b));
}
char t[200001], p[200001], tn[200001];
int nt, np;
bool bs(int mid) {
  int i, k = 0;
  for (i = 0; i < nt; i++) {
    if (tn[i] <= mid) continue;
    if (t[i] == p[k]) k++;
  }
  if (k == np)
    return true;
  else
    return false;
}
int main() {
  int i, a, b, start, end, mid, prev = 0;
  ;
  cin >> t;
  nt = strlen(t);
  cin >> p;
  np = strlen(p);
  for (i = 0; i < nt; i++) {
    sc(a);
    tn[a - 1] = i;
  }
  start = 0;
  end = nt - 1;
  while (start <= end) {
    mid = (start + end) >> 1;
    if (bs(mid) == true) {
      prev = mid;
      start = mid + 1;
    } else
      end = mid - 1;
  }
  printf("%d\n", prev + 1);
  return 0;
}
