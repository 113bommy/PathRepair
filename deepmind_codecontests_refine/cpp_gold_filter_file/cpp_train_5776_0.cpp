#include <bits/stdc++.h>
using namespace std;
string s;
long long int cnt[500005];
double avg = 0.0;
bool check(char c) {
  if (c == 'I' || c == 'E' || c == 'A' || c == 'O' || c == 'U' || c == 'Y')
    return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  int n = int((s).length());
  s = "#" + s;
  for (int i = 1; i <= n; i++) {
    cnt[i] = cnt[i - 1];
    if (check(s[i])) cnt[i]++;
  }
  long long int cur = cnt[n];
  avg = 0.0;
  for (int m = int(1); m <= int(n); ++m) {
    avg += cur / (m + 0.0);
    if (m > n - m + 1) {
      cur -= cnt[m] - cnt[n - m];
    } else {
      cur += cnt[n - m] - cnt[m];
    }
  }
  printf("%.9f\n", avg);
  return 0;
}
