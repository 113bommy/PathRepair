#include <bits/stdc++.h>
using namespace std;
string a, b;
char get(char ch1, char ch2) {
  for (int i = 'a'; i <= 'z'; i++)
    if (i != ch1 && i != ch2) return (char)i;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  cin >> a >> b;
  int cnt = 0;
  for (int i = 0; i < n; i++) cnt += (a[i] != b[i]);
  if ((cnt - k) * 2 > cnt)
    cout << -1 << '\n';
  else if (cnt > k) {
    cnt = cnt - k;
    string ans = a;
    bitset<100010> bs;
    bs.reset();
    for (int i = 0, j = 0; i < n && j < cnt; i++) {
      if (a[i] != b[i]) {
        ans[i] = a[i];
        bs[i] = 1;
        j++;
      }
    }
    for (int i = 0, j = 0; j < n && j < cnt; i++) {
      if (a[i] != b[i] && !bs[i]) {
        ans[i] = b[i];
        bs[i] = 1;
        j++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (!bs[i] && a[i] != b[i]) {
        ans[i] = get(a[i], b[i]);
      }
    }
    cout << ans << '\n';
  } else {
    int dif = k - cnt;
    string ans = a;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        ans = get(a[i], b[i]);
      } else if (a[i] == b[i] && dif) {
        ans = get(a[i], b[i]);
        dif--;
      } else {
        ans = a[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
