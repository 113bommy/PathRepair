#include <bits/stdc++.h>
using namespace std;
const int N = 2000100;
int n, x, y;
int c[N];
long long s[N];
bool pr[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> x >> y;
  int a;
  memset((c), (0), sizeof(c));
  memset((s), (0), sizeof(s));
  memset((pr), (0), sizeof(pr));
  for (int i = (int)0; i < (int)n; ++i) {
    cin >> a;
    c[a]++;
    s[a] += a;
  }
  for (int i = (int)1; i < (int)N; ++i) c[i] += c[i - 1], s[i] += s[i - 1];
  long long ans = 0x3f3f3f3f3f3f3f3f;
  for (int i = (int)2; i < (int)N; ++i)
    if (!pr[i]) {
      for (int j = i + i; j < N; j += i) pr[j] = 1;
      long long res = 0;
      int z = min(i, x / y + 1);
      for (int j = i; j < N; j += i) {
        res += 1LL * ((c[j] - c[j - z]) * j - 1LL * (s[j] - s[j - z])) * y;
        res += 1LL * (c[j - z] - c[j - i]) * x;
      }
      ans = min(ans, res);
    }
  cout << ans;
  return 0;
}
