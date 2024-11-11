#include <bits/stdc++.h>
using namespace std;
const int oo = 1000000007;
int a[1000009];
int num[20];
int b[] = {1, 3, 2, 6, 4, 5};
int c[] = {6, 8, 1, 9};
int main() {
  string s;
  memset(num, 0, sizeof(num));
  memset(a, 0, sizeof(a));
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) num[s[i] - '0']++;
  bool bb = 0;
  num[6]--;
  num[8]--;
  num[1]--;
  num[9]--;
  int cnt = 4;
  for (int i = 0; i < 10; i++)
    while (num[i]--) a[cnt++] = i;
  int ans = 0;
  for (int i = 0; i < n; i++) ans = (ans + b[i % 7] * a[n - i - 1]) % 7;
  int z = 0;
  do {
    z = 0;
    for (int i = 0; i < 4; i++) z += c[i] * b[(n - i - 1) % 7];
    if ((z + ans) % 7 == 0)
      for (int i = 0; i < 4; i++) a[i] = c[i];
  } while (next_permutation(c, c + 4));
  for (int i = 0; i < n; i++) printf("%d", a[i]);
  return 0;
}
