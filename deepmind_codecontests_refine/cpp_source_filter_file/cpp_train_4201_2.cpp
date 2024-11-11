#include <bits/stdc++.h>
using namespace std;
char s[150000];
int tot = 150000, sum[150000];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  for (int i = 1; i <= len; ++i) {
    sum[i] = sum[i - 1];
    if (s[i - 1] <= 'Z' && s[i - 1] >= 'A') sum[i]++;
  }
  for (int i = 1; i <= len; ++i) tot = min(tot, i - sum[i] + sum[len] - sum[i]);
  cout << tot << endl;
  return 0;
}
