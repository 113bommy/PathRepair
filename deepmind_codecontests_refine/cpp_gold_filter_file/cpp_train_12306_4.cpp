#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int M = 100016, MOD = 1000000007;
int bit[30];
int cnt[30];
int p;
long long C[30][30];
long long cal(int k) {
  long long tmp = 1;
  long long f = 1;
  for (int i = k; i; i--) {
    tmp = tmp * C[f][cnt[i]];
    f -= cnt[i];
    f++;
  }
  return tmp;
}
int main(void) {
  for (int i = 0; i < 30; i++)
    for (int j = 0; j < 30; j++)
      if (j == 0 || i == j)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  int t;
  long long n;
  t = read();
  while (t--) {
    n = read();
    if (n == 0) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 0; i < 30; i++) bit[i] = cnt[i] = 0;
    p = 0;
    for (int i = 2; i <= 100; i++) {
      p = i;
      bit[i] = n % i;
      cnt[bit[i]]++;
      n /= i;
      if (n == 0) break;
    }
    long long ans = 0;
    if (cnt[p - 1] == 1)
      ans = cal(p - 1);
    else
      for (int i = 1; i <= p - 1; i++)
        if (cnt[i] > 0) {
          cnt[i]--;
          ans += cal(p - 2);
          cnt[i]++;
        }
    cout << ans - 1 << endl;
  }
  return 0;
}
