#include <bits/stdc++.h>
using namespace std;
const long long maxn = 4e5 + 10;
long long line[maxn];
long long tuer[maxn];
long long poww(long long a, long long b, long long n) {
  long long d = 1, t = a;
  while (b > 0) {
    if (b % 2 == 1) d = d * t % n;
    b = b / 2;
    t = t * t % n;
  }
  return d % n;
}
int main() {
  long long n, L;
  cin >> n >> L;
  long long k = poww((long long)2, (long long)8 * L / n, 1e12);
  if (k <= 0) {
    cout << "0";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> line[i];
  }
  line[0] = -1;
  sort(line + 1, line + 1 + n);
  long long ac = 0;
  long long ko = 0;
  int j = 1;
  while (1) {
    if (ko > k || j > n) {
      if (j > n)
        j--;
      else
        j -= 2;
      break;
    }
    if (line[j] != line[j - 1]) {
      ko++;
    }
    j++;
  }
  ac = n - j;
  int i = 1;
  while (1) {
    i++;
    if (line[i] != line[i - 1]) {
      j++;
      while (j < n && line[j] == line[j + 1]) j++;
    }
    if (ac > n - (j - i + 1)) ac = n - (j - i + 1);
    if (j > n || i > n) break;
  }
  cout << ac << endl;
  return 0;
}
