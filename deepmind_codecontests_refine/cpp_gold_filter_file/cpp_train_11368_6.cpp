#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 29);
bool is_p(int x) {
  for (int i = 2; i <= sqrt(x); ++i) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> Free(1, 0);
  for (int i = 0; i <= n; ++i) {
    if (i * 2 > n && is_p(i)) {
      Free.push_back(i - 1);
    }
  }
  int m = Free.size();
  int cnt[26];
  char c[26];
  for (int i = 0; i < 26; ++i) {
    c[i] = i + 'a';
    cnt[i] = 0;
    for (int j = 0; j < n; ++j) {
      if (s[j] == c[i]) {
        ++cnt[i];
      }
    }
  }
  int mx = 0;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] > cnt[mx]) {
      mx = i;
    }
  }
  swap(cnt[mx], cnt[25]);
  swap(c[mx], c[25]);
  if (cnt[25] < (n - m)) {
    puts("NO");
    exit(0);
  }
  cout << "YES\n";
  int j = 0, w = 0, l = 0;
  for (int i = 0; i < n; ++i) {
    while (j < 26 && w == cnt[j]) {
      w = 0;
      ++j;
    }
    if (l < m && i == Free[l]) {
      cout << c[j];
      ++l, ++w;
    } else {
      cout << c[25];
    }
  }
  return 0;
}
