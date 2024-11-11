#include <bits/stdc++.h>
using namespace std;
char str1[1024], str2[1024];
unsigned int sum1 = 0, sum2 = 0;
unsigned int n, len1, len2;
unsigned int GetLcm(unsigned, unsigned);
void Compute(unsigned int);
bool FirstWin(int, int);
bool SecondWin(int, int);
int main() {
  cin >> n;
  cin >> str1 >> str2;
  len1 = strlen(str1);
  len2 = strlen(str2);
  unsigned int lcm = GetLcm(len1, len2);
  if (n >= lcm) Compute(lcm);
  sum1 *= (n / lcm);
  sum2 *= (n / lcm);
  Compute(n % lcm);
  cout << sum1 << ' ' << sum2;
  return 0;
}
unsigned int GetLcm(unsigned int x, unsigned int y) {
  unsigned int mul = x * y;
  unsigned int t;
  if (x < y) {
    t = x;
    x = y;
    y = t;
  }
  t = x % y;
  while (t) {
    x = y;
    y = t;
    t = x % y;
  }
  return (mul / y);
}
void Compute(unsigned int round) {
  unsigned int i;
  int k = 0, j = 0;
  for (i = 1; i <= round; ++i) {
    if (FirstWin(j, k))
      sum2++;
    else if (SecondWin(j, k))
      sum1++;
    j = (j + 1) % len1;
    k = (k + 1) % len2;
  }
}
bool FirstWin(int j, int k) {
  return (str1[j] == 'P' && str2[k] == 'R' ||
          str1[j] == 'R' && str2[k] == 'S' || str1[j] == 'S' && str2[k] == 'P');
}
bool SecondWin(int j, int k) {
  return (str1[j] == 'P' && str2[k] == 'S' ||
          str1[j] == 'R' && str2[k] == 'P' || str1[j] == 'S' && str2[k] == 'R');
}
