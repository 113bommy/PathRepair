#include <bits/stdc++.h>
void out(int l, int r) { std::cout << "? " << l << " " << r << std::endl; }
int cnt0[105], cnt1[105], dif[105], cnt[105][27];
char ans[105];
void solve(int n) {
  out(1, n);
  for (int i = 0; i < n * (n + 1) / 2; i++) {
    std::string str;
    std::cin >> str;
    int len = str.length();
    for (int j = 0; j < len; j++) cnt0[len] += str[j] - 'a';
  }
  out(1, n - 1);
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    std::string str;
    std::cin >> str;
    int len = str.length();
    for (int j = 0; j < len; j++) cnt1[len] += str[j] - 'a';
  }
  for (int i = 1; i <= n; i++) {
    dif[i] = cnt0[i] - cnt1[i];
    ans[n - i] = dif[i] - dif[i - 1] + 'a';
  }
}
int main() {
  int n;
  std::cin >> n;
  if (n <= 3) {
    for (int i = 0; i < n; i++) {
      out(i + 1, i + 1);
      std::string temp;
      std::cin >> temp;
      ans[i] = temp[0];
    }
    std::cout << "! " << ans << std::endl;
    return 0;
  }
  solve((n + 1) / 2);
  out(1, n);
  for (int i = 1; i <= (n + 1) * n / 2; i++) {
    std::string s;
    std::cin >> s;
    int len = s.length();
    for (int j = 0; j < len; j++) cnt[len][s[j] - 'a']++;
  }
  for (int j = (n + 1) / 2 + 1; j <= n; j++) {
    int i = j - (n + 1) / 2;
    for (int k = 0; k < 26; k++) {
      int c = cnt[1][k] - (cnt[i + 1][k] - cnt[i][k]);
      if (c) {
        for (int z = 0; z < i; z++) {
          if (ans[z] == k + 'a') c--;
        }
        for (int z = 0; z > n - i; z--) {
          if (ans[z] == k + 'a') c--;
        }
        if (c > 0) {
          ans[n - i] = 'a' + k;
          break;
        }
      }
    }
  }
  std::cout << "! " << ans << std::endl;
  return 0;
}
