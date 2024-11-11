#include <bits/stdc++.h>
const double pi = acos(-1.0);
const long long mod = 25 * 1E8;
using namespace std;
int pos1[205];
int pos2[205];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  char s[205];
  cin >> s;
  int len = strlen(s);
  int k;
  cin >> k;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == '?')
      pos1[cnt1++] = i;
    else if (s[i] == '*')
      pos2[cnt2++] = i;
  }
  int n = len - cnt1 - cnt2;
  if (n < k && cnt2 != 0) {
    int j = pos2[0];
    for (int i = 0; i < len; i++) {
      if (i == j) {
        int t = k - n;
        while (t--) printf("%c", s[j]);
      } else if (s[i] >= 'a' && s[i] <= 'z')
        printf("%c", s[i]);
    }
  } else if (n == k) {
    for (int i = 0; i < len; i++) {
      if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]);
    }
  } else if (n > k && n - k <= cnt1 + cnt2) {
    int j = n - k;
    int cnt3 = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == '?') {
        s[i - 1] = '0';
        cnt3++;
      } else if (s[i] == '*') {
        s[i - 1] = '0';
        cnt3++;
      }
      if (cnt3 == j) break;
    }
    for (int i = 0; i < len; i++) {
      if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]);
    }
  } else
    puts("Impossible");
  return 0;
}
