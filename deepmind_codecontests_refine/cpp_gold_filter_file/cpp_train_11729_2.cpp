#include <bits/stdc++.h>
using namespace std;
int n;
char s1[100005], s2[100005], s3[100005];
int num1[100], num2[100], num3[100];
int main() {
  while (cin >> n) {
    scanf("%s%s%s", s1, s2, s3);
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));
    memset(num3, 0, sizeof(num3));
    int len = strlen(s1);
    for (int i = 0; i < len; i++) num1[s1[i] - 'A']++;
    for (int i = 0; i < len; i++) num2[s2[i] - 'A']++;
    for (int i = 0; i < len; i++) num3[s3[i] - 'A']++;
    int n1 = 0, n2 = 0, n3 = 0;
    for (int i = 0; i < 100; i++) n1 = max(n1, num1[i]);
    for (int i = 0; i < 100; i++) n2 = max(n2, num2[i]);
    for (int i = 0; i < 100; i++) n3 = max(n3, num3[i]);
    if (n1 == len && n == 1)
      n1--;
    else
      n1 += n;
    if (n2 == len && n == 1)
      n2--;
    else
      n2 += n;
    if (n3 == len && n == 1)
      n3--;
    else
      n3 += n;
    if (n1 > len) n1 = len;
    if (n2 > len) n2 = len;
    if (n3 > len) n3 = len;
    if (n1 > n2 && n1 > n3)
      printf("Kuro\n");
    else if (n2 > n1 && n2 > n3)
      printf("Shiro\n");
    else if (n3 > n1 && n3 > n2)
      printf("Katie\n");
    else
      printf("Draw\n");
  }
  return 0;
}
