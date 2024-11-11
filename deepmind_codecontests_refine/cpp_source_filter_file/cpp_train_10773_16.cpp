#include <bits/stdc++.h>
using namespace std;
long long f(long long start, long long end, char s[]) {
  if (start > end) return 0;
  long long i, a, b, temp, j;
  a = 0;
  b = 0;
  for (i = start; s[i] != '+' && s[i] != '*' && i <= end; i++) {
    b = 10 * b + s[i] - '0';
  }
  i++;
  if (i <= end)
    for (; i <= end;) {
      temp = 0;
      for (j = i; s[j] != '+' && s[j] != '*' && j <= end; j++)
        temp = 10 * temp + s[j] - '0';
      if (s[i - 1] == '*')
        b = b * (temp);
      else {
        a += b;
        b = temp;
      }
      i = j + 1;
    }
  return a + b;
}
int main() {
  char s[5005];
  char s1[5005];
  char s2[5005];
  long long i, j, l, it, l1, k, k1;
  scanf("%s", s);
  l = strlen(s);
  s1[0] = '1';
  s1[1] = '*';
  for (i = 0; i < l; i++) {
    s1[i + 2] = s[i];
  }
  s1[l + 2] = '*';
  s1[l + 3] = '1';
  s1[l + 4] = 0;
  l = strlen(s1);
  vector<long long> mul;
  for (i = 0; i < l; i++)
    if (s1[i] == '*') mul.push_back(i);
  long long maxi = 0;
  long long ans, temp;
  for (i = 0; i < mul.size(); i++) {
    for (j = i + 1; j <= mul.size() - 1; j++) {
      k = 0;
      temp = f(mul[i] + 1, mul[j] - 1, s1);
      long long te1 = 0;
      while (temp) {
        s2[te1++] = temp % 10 + '0';
        temp /= 10;
      }
      s2[te1] = 0;
      for (k1 = 0; k1 < mul[i] + 1; k1++) s[k++] = s1[k1];
      long long k12 = strlen(s2);
      for (k1 = k12 - 1; k1 >= 0; k1--) s[k++] = s2[k1];
      for (k1 = mul[j]; k1 <= l; k1++) s[k++] = s1[k1];
      l1 = strlen(s);
      ans = f(0, l1 - 1, s);
      maxi = max(maxi, ans);
    }
  }
  printf("%lld", maxi);
  return 0;
}
