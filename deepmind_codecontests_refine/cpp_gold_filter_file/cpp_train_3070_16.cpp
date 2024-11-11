#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char a[100002];
  char b[100002];
  scanf("%s", &a);
  scanf("%s", &b);
  int i;
  bool flag = 0;
  for (i = 0; a[i] != '\0'; ++i) {
    if (a[i] != b[i]) {
      if (flag) a[i] = b[i];
      flag = !flag;
    }
  }
  if (!flag)
    printf("%s\n", a);
  else
    printf("impossible\n");
  return 0;
}
