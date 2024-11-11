#include <bits/stdc++.h>
using namespace std;
int n, cnt[4];
string s, t = "AGCT";
long long r, n1;
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++)
      if (s[i] == t[j]) cnt[j]++;
  sort(cnt, cnt + 4, greater<int>());
  for (int i = 0; i < 4; i++) {
    n1++;
    if (cnt[i] != cnt[i + 1]) break;
  }
  r = 1;
  for (int i = 0; i < n; i++) r = r * n1 % 1000000007L;
  cout << r << endl;
  return 0;
}
