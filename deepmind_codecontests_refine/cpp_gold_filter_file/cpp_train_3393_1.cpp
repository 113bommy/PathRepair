#include <bits/stdc++.h>
using namespace std;
int n, a[10000 + 1];
string s[100];
void doc() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
}
int chuyen(int l, int r) {
  int ans = 0;
  char c;
  string s1 = s[l], s2 = s[r];
  while (s1 != s2) {
    ans++;
    c = s1[0];
    for (int i = 0; i < s1.length() - 1; i++) {
      s1[i] = s1[i + 1];
    }
    s1[s1.length() - 1] = c;
    if (ans > s1.length()) return 10000;
  }
  return ans;
}
void xl() {
  int dem, kq = 10000;
  for (int i = 1; i <= n; i++) {
    dem = 0;
    for (int j = 1; j <= n; j++) {
      if (i != j) dem += chuyen(j, i);
    }
    kq = min(dem, kq);
  }
  if (kq < 10000)
    cout << kq;
  else
    cout << "-1";
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  doc();
  xl();
}
