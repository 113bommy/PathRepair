#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2048;
const long long MOD = 1000000007;
bool visited[MAXN][MAXN];
long long cache[MAXN][MAXN];
long long factorial[MAXN];
void factorial_init() {
  factorial[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    factorial[i] = (factorial[i - 1] * i) % MOD;
  }
}
long long D(int n, int m) {
  if (n < 0) return 0;
  if (n == 0) return factorial[m];
  long long &s = cache[n][m];
  if (visited[n][m]) return s;
  visited[n][m] = true;
  s = (m * D(n - 1, m) + (n - 1) * D(n - 2, m + 1)) % MOD;
  return s;
}
int a[MAXN];
bool pos[MAXN];
int TestNum;
int main() {
  factorial_init();
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];
  int n = N;
  for (int i = 1; i <= N; i++) {
    if (a[i] != -1) {
      n--;
      pos[i] = true;
    }
  }
  int m = 0;
  for (int i = 1; i <= N; i++) {
    if (a[i] != -1) {
      int t = a[i];
      if (!pos[t]) m++;
    }
  }
  cout << D(n, m) << endl;
}
