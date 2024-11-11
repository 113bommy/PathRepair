#include <bits/stdc++.h>
using namespace std;
long long v[100510];
long long sum[100510];
int mem[100510];
int main() {
  int n;
  int i, j, k;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v, v + n);
  sum[0] = v[0];
  for (i = 1; i < n; i++) {
    sum[i] = v[i] + sum[i - 1];
  }
  int m;
  cin >> m;
  memset(mem, -1, sizeof(mem));
  for (i = 0; i < m; i++) {
    cin >> k;
    if (n == 1) {
      cout << 0 << " ";
      continue;
    }
    if (mem[k] != -1) {
      cout << mem[k] << endl;
      continue;
    }
    long long p = 1;
    long long ini = n - 2;
    long long s = 0;
    long long t = k;
    long long fim = 0;
    while (ini >= fim && ini >= 0 && ini < n && fim >= 0 && fim < n) {
      if (ini < 0) break;
      long long fim = ini - t + 1;
      if (fim < 0) {
        long long r = p * (sum[ini] - sum[0] + v[0]);
        s += r;
        break;
      }
      long long r = p * (sum[ini] - sum[fim] + v[fim]);
      s += r;
      ini -= t;
      t *= k;
      p++;
    }
    mem[k] = s;
    cout << s << " ";
  }
  cout << endl;
  return 0;
}
