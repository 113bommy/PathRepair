#include <bits/stdc++.h>
using namespace std;
char ss[110];
int N, ans;
int main() {
  scanf("%s", ss + 1);
  N = strlen(ss + 1);
  for (int i = 1; i <= N; ++i)
    if (ss[i] == '1' || ss[i] == '3' || ss[i] == '5' || ss[i] == '7' ||
        ss[i] == '9' || ss[i] == 'a' || ss[i] == 'e' || ss[i] == 'i' ||
        ss[i] == 'o' || ss[i] == 'u')
      ++ans;
  printf("%d\n", ans);
  return 0;
}
