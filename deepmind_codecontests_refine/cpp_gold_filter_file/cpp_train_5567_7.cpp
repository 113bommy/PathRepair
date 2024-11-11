#include <bits/stdc++.h>
using namespace std;
static const int N = 30001;
int m[500][N];
int n, d;
int v[N];
int h[3] = {-1, 0, 1};
int f(int pos, int dif) {
  if (m[250 + dif][pos] == -1) {
    m[250 + dif][pos] = 0;
    for (int i = 0; i < 3; i++)
      if ((pos + d + dif + h[i] < N) && (d + dif + h[i] > 0) &&
          m[250 + dif][pos] < f(pos + d + dif + h[i], dif + h[i]))
        m[250 + dif][pos] = f(pos + d + dif + h[i], dif + h[i]);
    m[250 + dif][pos] += v[pos];
  }
  return m[250 + dif][pos];
}
int main() {
  int p;
  scanf("%i", &n);
  scanf("%i", &d);
  for (int i = 0; i < n; i++) {
    scanf("%i", &p);
    v[p]++;
  }
  for (int i = 0; i < 500; i++)
    for (int j = 0; j < N; j++) m[i][j] = -1;
  printf("%i\n", v[0] + f(d, 0));
  return 0;
}
