#include <bits/stdc++.h>
using namespace std;
int a[1000];
struct p {
  int id, num;
} e[1000];
bool com(p x, p y) { return x.num > y.num; }
int min(int x, int y) { return x < y ? x : y; }
int main() {
  int i = 0, n = 0, k = 0, ss = 0;
  cin >> n >> k;
  for (i = 1; i <= 2 * n + 1; i++) {
    scanf("%d", &a[i]);
  }
  int j = 1;
  for (i = 1; i <= 2 * n; i++) {
    if (i % 2 == 0) {
      ss = min(a[i - 1], a[i + 1]);
      e[j].num = a[i] - ss;
      e[j].id = i;
      j++;
    }
  }
  sort(e + 1, e + 1 + n, com);
  for (i = 1; i <= k; i++) {
    a[e[i].id]--;
  }
  for (i = 1; i <= 2 * n + 1; i++) {
    printf("%d ", a[i]);
  }
  cout << endl;
  return 0;
}
