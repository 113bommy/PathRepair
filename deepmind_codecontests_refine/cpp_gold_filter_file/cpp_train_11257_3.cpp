#include <bits/stdc++.h>
using namespace std;
int num[200100] = {0};
char s[200100];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  char t = 0;
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == t && cnt < k)
      cnt++;
    else {
      t = s[i];
      cnt = 1;
    }
    if (cnt == k) num[t]++;
  }
  int res = 0;
  for (int i = 0; i < 200099; i++) res = max(res, num[i]);
  printf("%d\n", res);
}
