#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int ss[N], l, kk, kkk, k, tot, id, sum;
char s[N];
int main() {
  cin >> s + 1;
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == '.') sum++;
    if (s[i] == '.' && s[i - 1] == '.') return puts("NO"), 0;
    if (s[i] >= 'A' && s[i] <= 'Z') return puts("NO"), 0;
  }
  if (sum == 0) {
    return puts("NO"), 0;
  }
  for (int i = 1; i <= n; i++)
    if (s[i] == '.') {
      ss[++tot] = i - 1;
      kk = i;
      if (i > 9)
        return puts("NO"), 0;
      else
        break;
    }
  if (kk == 1) return puts("NO"), 0;
  for (int i = n; i >= 1; i--)
    if (s[i] == '.') {
      k = i;
      if (n - i > 3)
        return puts("NO"), 0;
      else
        break;
    }
  if (k == n) return puts("NO"), 0;
  kkk = kk;
  for (int i = kkk + 1; i <= n; i++) {
    if (s[i] == '.') {
      if (i - kk - 1 > 11) return puts("NO"), 0;
      ss[++tot] = i - kk - 1;
      if (ss[tot] == 1) return puts("NO"), 0;
      kk = i;
    }
    if (i == k) break;
  }
  cout << "YES" << endl;
  id = 1;
  l = ss[1] + 2;
  for (int i = 1; i <= ss[1]; i++) cout << s[i];
  cout << ".";
  while (id < tot) {
    id++;
    if (ss[id] > 3) {
      for (int i = l; i <= l + 2; i++) cout << s[i];
      cout << endl;
      for (int i = l + 3; i <= l + ss[id] - 1; i++) cout << s[i];
      cout << ".";
    } else {
      cout << s[l] << endl;
      for (int i = l + 1; i <= l + ss[id] - 1; i++) cout << s[i];
      cout << ".";
    }
    l += ss[id] + 1;
  }
  for (int i = k + 1; i <= n; i++) cout << s[i];
}
