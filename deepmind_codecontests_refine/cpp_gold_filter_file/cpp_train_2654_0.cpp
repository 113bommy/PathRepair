#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, a, b, head1[200200], list1[200200], next1[200200], size1,
    use[200200];
long long res, kol, kol1;
void push(int a, int b);
void dfs(int a, int c);
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) head1[i] = -1;
  for (i = 0; i < m; i++) {
    scanf("%i %i", &a, &b);
    push(a - 1, b - 1);
    push(b - 1, a - 1);
  }
  if (m == 0) {
    cout << 3 << " " << n * (n - 1) * (n - 2) / 6;
    return 0;
  }
  for (i = 0; i < n; i++)
    if (head1[i] != -1 && next1[head1[i]] != -1) break;
  if (i == n) {
    cout << 2 << " " << m * (n - 2);
    return 0;
  }
  for (i = 0; i < n; i++)
    if (!use[i]) {
      kol = kol1 = 0;
      dfs(i, 1);
      res += kol * (kol - 1) / 2 + kol1 * (kol1 - 1) / 2;
    }
  for (i = 0; i < n; i++) {
    j = head1[i];
    while (j != -1) {
      if (use[i] == use[list1[j]]) {
        cout << 0 << " " << 1;
        return 0;
      }
      j = next1[j];
    }
  }
  cout << 1 << " " << res;
  return 0;
}
void push(int a, int b) {
  list1[size1] = b;
  next1[size1] = head1[a];
  head1[a] = size1;
  size1++;
}
void dfs(int a, int c) {
  int i;
  use[a] = c;
  if (c == 1)
    kol++;
  else
    kol1++;
  i = head1[a];
  while (i != -1) {
    if (!use[list1[i]]) dfs(list1[i], 3 - c);
    i = next1[i];
  }
}
