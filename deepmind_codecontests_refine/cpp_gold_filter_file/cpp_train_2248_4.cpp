#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
char cc[N + 2];
int qu[N];
int count(int *aa, int n, int m) {
  int k = 1;
  for (int a = 0, i = 0; i < n; i++) {
    if (a + aa[i] > m) {
      k++;
      a = 0;
    }
    a += aa[i];
  }
  return k;
}
int main() {
  int k;
  cin >> k;
  fgets(cc, N + 2, stdin);
  fgets(cc, N + 2, stdin);
  int n = strlen(cc) - 1;
  int cnt = 0;
  for (int c = 0, i = 0; i <= n; i++)
    if (i == n || cc[i] == '-' || cc[i] == ' ') {
      qu[cnt++] = c + 1;
      c = 0;
    } else
      c++;
  qu[cnt - 1]--;
  int a = 0;
  for (int h = 0; h < cnt; h++) a = max(a, qu[h]);
  int lower = a - 1, upper = n;
  while (upper - lower > 1) {
    int m = (lower + upper) / 2;
    if (count(qu, cnt, m) <= k)
      upper = m;
    else
      lower = m;
  }
  cout << upper << '\n';
  return 0;
}
