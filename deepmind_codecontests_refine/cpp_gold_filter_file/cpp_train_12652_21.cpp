#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n) {
  if (n == 2) return true;
  if (n % 2 == 0 || n < 2) return false;
  for (int i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}
long long comb(long long a, long long b) {
  long long res = 1;
  if (a == 0 || b == 0) return 1;
  int cnt[31] = {}, x = a - b;
  for (int j = 2; j <= a; j++) {
    int h = j;
    for (int i = 2; i <= h; i++) {
      while (h % i == 0) {
        h /= i;
        cnt[i]++;
      }
    }
  }
  for (int j = 2; j <= b; j++) {
    int h = j;
    for (int i = 2; i <= h; i++) {
      while (h % i == 0) {
        h /= i;
        cnt[i]--;
      }
    }
  }
  for (int j = 2; j <= x; j++) {
    int h = j;
    for (int i = 2; i <= h; i++) {
      while (h % i == 0) {
        h /= i;
        cnt[i]--;
      }
    }
  }
  for (int i = 1; i <= 30; i++) {
    if (cnt[i] > 0) {
      while (cnt[i] > 0) {
        cnt[i]--;
        res *= i;
      }
    }
  }
  return res;
}
int main() {
  int cnt[200000] = {}, res = 0;
  int a, ta, b, tb, h, m;
  char c;
  cin >> a >> ta >> b >> tb >> h >> c >> m;
  int x = 300 * 60;
  for (int i = h * 60 * 60 + m * 60 + 1; i < h * 60 * 60 + m * 60 + ta * 60;
       i++) {
    cnt[i % (1440 * 60)]++;
  }
  while (x <= 1439 * 60) {
    int z = 0;
    for (int i = x; i <= x + tb * 60; i++) {
      if (cnt[i % (1440 * 60)] > 0) z = 1;
    }
    if (z == 1) res++;
    x += b * 60;
  }
  cout << res;
}
