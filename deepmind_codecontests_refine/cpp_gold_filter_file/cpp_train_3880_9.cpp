#include <bits/stdc++.h>
using namespace std;
char str[100003];
int cnt[13], cnt1[5][13], ans3[13];
string ans1, ans2;
bool cmp(char a, char b) { return a > b; }
int main() {
  int len, i, max1, ans, j, sum, p, k;
  scanf("%s", str);
  len = strlen(str);
  for (i = 0; i < len; i++) {
    cnt[str[i] - '0']++;
  }
  max1 = 0;
  ans = -1;
  for (i = 0; i < 10; i++) {
    if ((i != 10 - i && cnt[i] && cnt[10 - i]) ||
        (i == 10 - i && cnt[i] >= 1)) {
      sum = 0;
      for (j = 0; j < 10; j++) cnt1[0][j] = cnt1[1][j] = 0;
      cnt1[0][i]++;
      cnt1[1][10 - i]++;
      sum++;
      for (j = 0; j < 10; j++) {
        p = min(cnt[j] - cnt1[0][j], cnt[9 - j] - cnt1[1][9 - j]);
        sum += p;
        cnt1[0][j] += p;
        cnt1[1][9 - j] += p;
      }
      p = min(cnt[0] - cnt1[0][0], cnt[0] - cnt1[1][0]);
      sum += p;
      cnt1[0][0] += p;
      cnt1[1][0] += p;
      if (sum > max1) {
        max1 = sum;
        ans = i;
      }
      ans3[i] = p;
    } else {
      max1 = max(max1, cnt[0]);
    }
  }
  if (!max1)
    printf("%s\n%s\n", str, str);
  else if (ans != -1) {
    i = ans;
    for (j = 0; j < 10; j++) cnt1[0][j] = cnt1[1][j] = 0;
    for (j = 0; j < ans3[i]; j++) {
      ans1.push_back('0');
      ans2.push_back('0');
      cnt1[0][0]++;
      cnt1[1][0]++;
    }
    cnt1[0][i]++;
    cnt1[1][10 - i]++;
    ans1.push_back(i + '0');
    ans2.push_back(10 - i + '0');
    for (j = 0; j < 10; j++) {
      p = min(cnt[j] - cnt1[0][j], cnt[9 - j] - cnt1[1][9 - j]);
      sum += p;
      cnt1[0][j] += p;
      cnt1[1][9 - j] += p;
      for (k = 0; k < p; k++) {
        ans1.push_back(j + '0');
        ans2.push_back(9 - j + '0');
      }
    }
    for (j = 0; j < 10; j++) {
      for (k = 0; k < cnt[j] - cnt1[0][j]; k++) ans1.push_back(j + '0');
      for (k = 0; k < cnt[j] - cnt1[1][j]; k++) ans2.push_back(j + '0');
    }
    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());
    cout << ans1 << endl << ans2 << endl;
  } else {
    sort(str, str + len, cmp);
    printf("%s\n%s\n", str, str);
  }
  return 0;
}
