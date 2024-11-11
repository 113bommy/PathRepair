#include <bits/stdc++.h>
using namespace std;
char s[200005];
int main() {
  scanf("%s", s);
  int n, t;
  scanf("%n", &n);
  int size = strlen(s);
  vector<int> v(size + 1);
  while (n--) {
    scanf("%d", &t);
    v[t - 1]++;
    v[size - t]--;
  }
  for (int j = 1; j < size; j++) v[j] += v[j - 1];
  int m = size - 1;
  for (int i = 0; i < m; i++) {
    if (v[i] % 2 != 0) swap(s[i], s[m]);
    m--;
  }
  printf("%s\n", s);
  return 0;
}
