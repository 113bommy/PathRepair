#include <bits/stdc++.h>
using namespace std;
int a[300000], b[300000];
int n;
int main(void) {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d", a + i);
    if (!a[i]) i--;
  }
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d", b + i);
    if (!b[i]) i--;
  }
  int st = 0;
  for (int i = 1; i <= n - 1; i++)
    if (a[i] == b[1]) {
      st = i;
      break;
    }
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] != b[st]) {
      cout << "NO";
      return 0;
    }
    if (++st == n) st = 1;
  }
  cout << "YES";
  return 0;
}
