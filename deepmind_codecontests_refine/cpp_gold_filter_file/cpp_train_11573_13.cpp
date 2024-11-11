#include <bits/stdc++.h>
using namespace std;
int htop[500010];
int hleft[500010];
string A[500010];
long long pw(long long a, long long p) {
  if (p == 0) return 1;
  long long x = pw(a, p / 2);
  long long ans = x * x;
  ans %= 1000003;
  if (p % 2 == 1) ans *= a;
  ans %= 1000003;
  return ans;
}
int main() {
  int N, M;
  cin >> N >> M;
  for (int r = 0; r < N; r++) {
    cin >> A[r];
  }
  bool ok = true;
  for (int r = 0; r < N && ok; r++) {
    for (int c = 0; c < M && ok; c++) {
      if (A[r][c] == '.') continue;
      int q = (A[r][c] - '0');
      int hasleft = (q == 1 || q == 2) ? 1 : 2;
      int hastop = (q == 1 || q == 4) ? 1 : 2;
      hastop += r % 2;
      hastop %= 2;
      hastop += 2 * (1 - hastop);
      hasleft += c % 2;
      hasleft %= 2;
      hasleft += 2 * (1 - hasleft);
      if (htop[c] != 0 && htop[c] != hastop) ok = false;
      if (hleft[r] != 0 && hleft[r] != hasleft) ok = false;
      htop[c] = hastop;
      hleft[r] = hasleft;
    }
  }
  if (!ok) {
    cout << 0 << endl;
    return 0;
  }
  int cnt = 0;
  for (int r = 0; r < N; r++) {
    bool has = false;
    for (int c = 0; c < M && !has; c++) {
      if (A[r][c] == '.') continue;
      has = true;
    }
    if (!has) cnt++;
  }
  for (int c = 0; c < M; c++) {
    bool has = false;
    for (int r = 0; r < N && !has; r++) {
      if (A[r][c] == '.') continue;
      has = true;
    }
    if (!has) cnt++;
  }
  long long ans = pw(2, cnt);
  cout << ans << endl;
}
