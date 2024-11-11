#include <bits/stdc++.h>
using namespace std;
int Pow[45], r[45], tmp[45];
vector<int> g;
int main() {
  int n;
  long long a;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a);
    bool p = true;
    int t = 0;
    while (1) {
      if (a == 1) {
        if (p)
          Pow[t + 1]++;
        else
          r[t + 1]++;
        break;
      }
      if (a & 1 != 0) p = false;
      a /= 2;
      t++;
    }
  }
  bool ans = false, end = false;
  int last;
  int num = Pow[1];
  int k = 0;
  while (num - k != 0) {
    Pow[1] = num - k;
    if (k) r[1]++;
    for (int i = 1; i < 44; i++) {
      if (Pow[i] < Pow[i + 1]) {
        r[i] += Pow[i + 1] - Pow[i];
        Pow[i + 1] = Pow[i];
      }
    }
    for (int i = 0; i <= 44; i++) tmp[i] = Pow[i];
    for (int i = 1; i <= 44; i++) {
      if (tmp[i] == 0) {
        last = i - 1;
        for (int j = i; j <= 44; j++)
          if (r[j] != 0) {
            end = true;
          }
        break;
      }
    }
    if (end) break;
    int pre = 0;
    int sum = 0;
    for (int i = last; i >= 0; i--) {
      if (tmp[last] != tmp[i]) {
        pre = i;
        sum = 0;
        for (int j = pre + 1; j <= last; j++) {
          sum += r[j];
        }
        if (sum > tmp[last]) end = true;
        for (int j = 1; j <= last; j++) tmp[j] -= sum;
        last = pre;
      }
    }
    if (end) break;
    g.push_back(num - k);
    ans = true;
    k++;
  }
  sort(g.begin(), g.end());
  if (!ans)
    printf("-1\n");
  else {
    for (int i = 0; i < g.size(); i++) printf("%d ", g[i]);
  }
}
