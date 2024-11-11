#include <bits/stdc++.h>
const long long int MOD = 1e9 + 7;
const long long int INF = 1011111111;
const long long int LLINF = 1000111000111000111LL;
const long double EPS = 1e-10;
const long double PI = 3.14159265358979323;
using namespace std;
long long int power(long long int x, long long int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return power((x * x), n / 2);
  else
    return x * power((x * x), (n - 1) / 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, i, j, k;
  string s;
  cin >> n;
  cin >> s;
  char ch[200505];
  memset(ch, '.', sizeof ch);
  long long int id = 0;
  ch[0] = s[0];
  long long int ans = 0;
  for (i = 1; i < n; i++) {
    if (id % 2 == 0 && s[i] == ch[id]) {
      ans++;
    } else {
      ch[++id] = s[i];
    }
  }
  if (id % 2 == 0) {
    ch[id] = '.';
    ans++;
  }
  cout << ans << '\n';
  for (i = 0; i <= id + 10; i++) {
    if (ch[i] != '.') cout << ch[i];
  }
}
