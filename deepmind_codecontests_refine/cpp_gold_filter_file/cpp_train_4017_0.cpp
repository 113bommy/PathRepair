#include <bits/stdc++.h>
using namespace std;
char a[100005], b[100005];
int main() {
  scanf("%s %s", &a, &b);
  int len1 = strlen(a);
  int len2 = strlen(b);
  if (strcmp(a, b) == 0) {
    printf("-1\n");
  } else {
    printf("%d\n", max(len1, len2));
  }
}
