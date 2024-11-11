#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const int N = 1e5 + 10;
int a[5];
int cnt[5];
int main() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < n; i++) {
    if (s1[i] == '0' && s2[i] == '0') a[1]++;
    if (s1[i] == '0' && s2[i] == '1') a[2]++;
    if (s1[i] == '1' && s2[i] == '0') a[3]++;
    if (s1[i] == '1' && s2[i] == '1') a[4]++;
  }
  int flag = 0;
  for (int i = 0; i <= a[3] && !flag; i++) {
    for (int j = 0; j <= a[4]; j++) {
      cnt[3] = a[2] - i - j + a[4] - j;
      if (cnt[3] >= 0 && cnt[3] <= a[3]) {
        cnt[1] = n / 2 - i - j - cnt[3];
        if (cnt[1] < 0 || cnt[1] > a[1]) continue;
        cnt[2] = i;
        cnt[4] = j;
        flag = 1;
        break;
      }
    }
  }
  if (!flag) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (s1[i] == '0' && s2[i] == '0' && cnt[1]) cout << i + 1 << " ", cnt[1]--;
    if (s1[i] == '0' && s2[i] == '1' && cnt[2]) cout << i + 1 << " ", cnt[2]--;
    if (s1[i] == '1' && s2[i] == '0' && cnt[3]) cout << i + 1 << " ", cnt[3]--;
    if (s1[i] == '1' && s2[i] == '1' && cnt[4]) cout << i + 1 << " ", cnt[4]--;
  }
  return 0;
}
