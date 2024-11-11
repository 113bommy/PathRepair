#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long s[1010];
long long mode(long long n) { return ((n % mod) + mod) % mod; }
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  memset(s, -1, sizeof(s));
  long long a, b;
  for (long long i = 0; i < n; i++) {
    cin >> a >> b;
    if (s[a] == -1)
      s[a] = b;
    else {
      long long xx = s[a];
      if (xx > b) s[a] = b;
    }
  }
  long long sum = 0;
  for (long long i = 1; i <= m; i++) {
    sum += s[i];
  }
  if (sum > k)
    cout << k << endl;
  else
    cout << sum << endl;
}
void abc() {
  int i, j, k;
  int n, m;
  int x, y;
  cin >> n;
  long long cnt = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      x = i ^ j;
      if (x <= n && x > 0) {
        k = 0;
        if (i + j <= x)
          k++;
        else if (i + x <= j)
          k++;
        else if (x + j <= i)
          k++;
        if (k <= 0) cnt++;
      }
    }
  }
  cout << cnt / 6;
}
void bcd() {
  string s, ss;
  cin >> s >> ss;
  int sum = 0, n = s.size(), nn = ss.size();
  for (int i = 0; i <= n - nn; i++) {
    int a = 0;
    for (int j = i; j < i + nn; j++) {
      if (s[j] == ss[j - i]) {
        a++;
      }
    }
    sum = max(a, sum);
  }
  cout << ss.size() - sum << endl;
}
void recur(int n) {
  if (n > 0) {
    printf("%d  ", n);
    recur(n - 1);
    recur(n - 1);
  }
}
int main() { solve(); }
