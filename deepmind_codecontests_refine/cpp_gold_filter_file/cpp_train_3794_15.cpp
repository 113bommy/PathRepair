#include <bits/stdc++.h>
using namespace std;
ifstream fin;
ofstream fout;
FILE *outt, *inn;
const int N = 100009, M = 70;
int k, b[M], d[M], k2, y, yy;
unsigned long long m, c[M][M], l, r, cur;
void find() {
  for (int i = 0; i <= 64; i++) {
    for (int j = 0; j <= 64; j++) {
      if (i == 0) {
        c[i][j] = 1;
        continue;
      }
      if (i > j) continue;
      c[i][j] = c[i - 1][j - 1] + c[i][j - 1];
    }
  }
}
int cnt;
bool is;
void binary(unsigned long long x) {
  memset(b, 0, sizeof(b));
  is = 0;
  cnt = 69;
  while (x > 0) {
    b[--cnt] = x % 2;
    x /= 2;
  }
  b[0] = cnt;
  for (int i = b[0] + 1; i <= 68; i++) {
    if (b[i]) {
      return;
    }
  }
  is = 1;
}
unsigned long long solve(unsigned long long x) {
  cur = 0;
  binary(2 * x);
  k2 = k - 1;
  for (int i = b[0] + 1; i <= 68; i++) {
    if (b[i] == 1) {
      y = 68 - i;
      cur += c[k2][y];
      k2--;
    }
    if (k2 == 0) {
      for (int j = i + 1; j <= 68; j++) {
        if (b[j]) {
          cur++;
          break;
        }
      }
      break;
    }
  }
  k2 = 0;
  for (int i = b[0]; i <= 68; i++) {
    if (b[i]) k2++;
  }
  if (k2 == k) cur++;
  binary(x + 1);
  if (!is) {
    k2 = k - 1;
    for (int i = b[0] + 1; i <= 68; i++) {
      if (b[i] == 0) {
        cur += c[k2 - 1][68 - i];
      }
      if (b[i] == 1) {
        k2--;
      }
      if (k2 == 0) {
        break;
      }
    }
    k2 = 0;
    for (int i = b[0]; i <= 68; i++) {
      if (b[i]) k2++;
    }
    if (k2 == k) cur++;
  }
  return cur;
}
int main() {
  memset(c, 0, sizeof(c));
  find();
  cin >> m >> k;
  r = (unsigned long long)1;
  while (solve(r) < m) {
    r *= 2;
  }
  l = r / 2 + 1;
  while (l < r) {
    unsigned long long mid = (l + r) / 2;
    unsigned long long res = solve(mid);
    if (res < m) {
      l = mid + 1;
    } else if (res > m) {
      r = mid - 1;
    } else {
      cout << mid;
      return 0;
    }
  }
  cout << l;
  return 0;
}
