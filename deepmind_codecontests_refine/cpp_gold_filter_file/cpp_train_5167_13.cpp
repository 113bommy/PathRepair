#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long a = 0, b = getchar(), c = 1;
  while (!isdigit(b)) c = b == '-' ? -1 : 1, b = getchar();
  while (isdigit(b)) a = a * 10 + b - '0', b = getchar();
  return a * c;
}
string s;
int ans = 1e9, a[200], b[200];
int main() {
  cin >> s;
  for (int j = 'a'; j <= 'z'; j++) {
    int k = 0, t = 0;
    for (int i = 0; i <= s.size(); i++) {
      k = max(k, ++t);
      if (s[i] == j) t = 0;
    }
    ans = min(ans, k);
  }
  cout << ans;
  return 0;
}
