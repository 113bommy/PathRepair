#include <bits/stdc++.h>
using namespace std;
set<int> S;
double pwr[44], ans;
int n;
pair<int, int> a[111111];
int p[44], q[44];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i].first), a[i].second = i;
  sort(a + 1, a + 1 + n);
  S.insert(0), S.insert(n + 1);
  pwr[0] = 1;
  for (int i = 1; i <= 40; ++i) pwr[i] = pwr[i - 1] * 2;
  for (int z = n; z >= 1; --z) {
    int i = a[z].second, v = a[z].first;
    S.insert(i);
    set<int>::iterator c = S.find(i);
    p[0] = i;
    double L = 0, R = 0;
    for (int j = 1; j <= 40; ++j) {
      if (c == S.begin()) break;
      c--;
      p[j] = *c;
      L += double(p[j - 1] - p[j]) / pwr[j];
    }
    c = S.find(i);
    q[0] = i;
    for (int j = 1; j <= 40; ++j) {
      c++;
      if (c == S.end()) break;
      q[j] = *c;
      R += double(q[j] - q[j - 1]) / pwr[j - 1];
    }
    ans += L * R * v;
  }
  printf("%.10f\n", ans / n / n);
}
