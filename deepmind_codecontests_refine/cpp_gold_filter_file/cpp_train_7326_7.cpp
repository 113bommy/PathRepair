#include <bits/stdc++.h>
using namespace std;
long long n, k, a[100005], aft[5500005][2], raod[5500005][2], cur, b[70],
    p[100005], ans, c;
void B(long long N) {
  for (int i = 1; i <= 67; i++) {
    b[i] = 0;
  }
  int i = 0;
  while (N > 0) {
    i++;
    b[i] = N % 2;
    N /= 2;
  }
}
void add(long long N) {
  B(N);
  int u = 0;
  for (int i = 67; i >= 1; i--) {
    if (aft[u][b[i]] == 0) {
      cur++;
      aft[u][b[i]] = cur;
    }
    raod[u][b[i]]++;
    u = aft[u][b[i]];
  }
}
void remove(long long N) {
  B(N);
  int u = 0;
  for (int i = 67; i >= 1; i--) {
    raod[u][b[i]]--;
    u = aft[u][b[i]];
  }
}
long long getans(long long N) {
  B(N);
  int u = 0;
  long long pas = 0;
  for (int i = 67; i >= 1; i--) {
    if (raod[u][1 - b[i]] != 0) {
      u = aft[u][1 - b[i]];
      pas += 1ll << (i - 1);
    } else
      u = aft[u][b[i]];
  }
  return pas;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  add(0);
  for (k = 1; k <= n; k++) {
    cin >> a[k];
    p[k] = p[k - 1] ^ a[k];
    add(p[k]);
    ans = max(ans, p[k]);
  }
  for (k = n; k >= 1; k--) {
    remove(p[k]);
    c = c ^ a[k];
    ans = max(ans, getans(c));
  }
  cout << max(p[n], ans);
}
