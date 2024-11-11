#include <bits/stdc++.h>
using namespace std;
pair<int, int> mas[200100];
int n;
long long base;
long long two_count, ans = 1;
long long f(int x) {
  long long res = 0;
  for (int i = 2; i <= x; i = i + i) res += x / i;
  return res;
}
int main() {
  scanf("%d", &n);
  n *= 2;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    int q;
    if (i <= n)
      q = i;
    else
      q = i - n;
    mas[i] = make_pair(x, q);
  }
  cin >> base;
  sort(mas + 1, mas + n + 1);
  for (int i = 1; i <= n; i++) {
    int st = i, fin = st;
    while (mas[fin].first == mas[st].first) fin++;
    fin--;
    long long pr = 0;
    for (int j = st; j < fin; j++) {
      if (mas[j].second == mas[j + 1].second) pr++, j++;
    }
    two_count += f(fin - st + 1) - pr;
    long long e = fin - st + 1;
    for (long long j = 1; j <= e; j++) {
      long long zz = j;
      while (zz % 2 == 0) zz /= 2;
      ans = ans * zz % base;
    }
    i = fin;
  }
  for (int j = 1; j <= two_count; j++) ans = ans + ans, ans %= base;
  cout << ans << endl;
  return 0;
}
