#include <bits/stdc++.h>
using namespace std;
long long cnt[1000009][26];
int gcd(int a, int b) {
  while (b > 0) {
    int tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  int g = gcd(a.length(), b.length());
  long long l = ((long long)a.length() * (long long)b.length()) / (long long)g;
  for (int i = 0; i < b.length(); ++i) cnt[i % g][b[i] - 'a']++;
  long long ans = 0;
  for (int i = 0; i < a.length(); ++i) {
    for (int j = 0; j < 26; ++j)
      if (a[i] - 'a' != j) ans += (long long)cnt[i % g][j];
  }
  cout << ans * ((long long)a.length() * n) / l << "\n";
  return 0;
}
