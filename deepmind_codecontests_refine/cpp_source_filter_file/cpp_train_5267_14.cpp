#include <bits/stdc++.h>
using namespace std;
int n, k;
char ch[233];
int Ans[233];
void print(int x) {
  if (x / 26)
    printf("B");
  else
    printf("A");
  printf("%c\n", 'a' + x % 26 - 1);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < k; i++) print(i), Ans[i] = i;
  for (int i = k; i <= n; i++) {
    scanf("%s", ch);
    if (ch[0] == 'N')
      Ans[i] = Ans[i - k + 1], print(Ans[i]);
    else
      Ans[i] = i, print(Ans[i]);
  }
  return 0;
}
