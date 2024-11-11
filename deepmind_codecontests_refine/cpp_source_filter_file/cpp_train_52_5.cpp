#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
using namespace std;
template <typename T>
vector<T> read_v(int n) {
  vector<T> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  return v;
}
bool decrease(int a, int b) { return (a > b); }
struct pr {
  int f, s;
};
char s[100];
int main() {
  int k = 0, n, pos = 1, neg = 0;
  while (true) {
    char c;
    scanf(" %c", &c);
    scanf(" %c", &c);
    if (c == '=') break;
    if (c == '+') pos++;
    if (c == '-') neg++;
    s[k++] = c;
  }
  scanf("%d", &n);
  if (pos - n * neg > n || n * pos - neg < n) {
    printf("Impossible\\n");
    return 0;
  }
  printf("Possible\\n");
  int S = 0;
  for (int i = 0; i < k; i++) {
    int sgn = 1;
    if (i > 0 && s[i - 1] == '-') sgn = -1;
    if (sgn == 1) pos--;
    if (sgn == -1) neg--;
    for (int x = 1; x <= n; x++)
      if (S + x * sgn + pos - n * neg <= n &&
          S + x * sgn + n * pos - neg >= n) {
        printf("%d %c ", x, s[i]);
        S += x * sgn;
        break;
      }
  }
  printf("%d = %d\\n", abs(n - S), n);
  return 0;
}
