#include <bits/stdc++.h>
inline int scan() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void Out(int a) {
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  if (a >= 10) Out(a / 10);
  putchar(a % 10 + '0');
}
using namespace std;
const int maxn = 100005;
char str1[maxn], str2[maxn], str3[maxn];
long long num1[205], num2[205], num3[200];
int main() {
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  cin >> str1 >> str2 >> str3;
  long long len1 = strlen(str1);
  long long len2 = strlen(str2);
  long long len3 = strlen(str3);
  long long max1 = 0, max2 = 0, max3 = 0;
  for (int i = 0; i < len1; i++)
    num1[str1[i] - 'A']++, max1 = max(max1, num1[str1[i] - 'A']);
  for (int i = 0; i < len2; i++)
    num2[str2[i] - 'A']++, max2 = max(max2, num2[str2[i] - 'A']);
  for (int i = 0; i < len3; i++)
    num3[str3[i] - 'A']++, max3 = max(max3, num3[str3[i] - 'A']);
  if (max1 + n >= len1) {
    if (n == 1 && max1 == len1)
      max1 = len1 - 1;
    else
      max1 = len1;
  } else
    max1 += n;
  if (max2 + n >= len2) {
    if (n == 1 && max1 == len1)
      max2 = len2 - 1;
    else
      max2 = len2;
  } else
    max2 += n;
  if (max3 + n > len3) {
    if (n == 1 && max3 == len3)
      max3 = len3 - 1;
    else
      max3 = len3;
  } else
    max3 += n;
  long long ans = max(max1, max(max2, max3));
  if ((ans == max2 && ans == max3) || (ans == max1 && ans == max2) ||
      (ans == max3 && ans == max1)) {
    cout << "Draw" << endl;
    return 0;
  }
  if (ans == max1) {
    cout << "Kuro" << endl;
  } else if (ans == max2) {
    cout << "Shiro" << endl;
  } else if (ans == max3) {
    cout << "Katie" << endl;
  }
  return 0;
}
