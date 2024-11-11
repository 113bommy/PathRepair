#include <bits/stdc++.h>
using namespace std;
int T, N, K, a[300001], val[300001];
int getc() {
  char c = getchar();
  while (c != '0' && c != '1' && c != '?') c = getchar();
  return c == '?' ? 2 : c - '0';
}
int main() {
  cin >> T;
  while (T--) {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) a[i] = getc();
    for (int i = 0; i <= K - 1; i++) val[i] = 2;
    bool flag = 1;
    for (int i = 1; i <= N; i++)
      if (val[i % K] == 2)
        val[i % K] = a[i];
      else if (a[i] + val[i % K] == 1) {
        flag = 0;
        break;
      }
    if (!flag) {
      cout << "NO\n";
      continue;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i <= K - 1; i++) cnt1 += val[i] == 1, cnt2 += val[i] == 2;
    cout << (K / 2 >= cnt1 && K / 2 <= cnt1 + cnt2 ? "YES\n" : "NO\n");
  }
  return 0;
}
