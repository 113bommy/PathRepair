#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int anc[100100], peso[100100];
int find(int x) {
  if (anc[x] == x) return x;
  return anc[x] = find(anc[x]);
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    peso[i] = 0;
    anc[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    a = find(a);
    b = find(b);
    anc[a] = b;
  }
  for (int i = 0; i < n; i++) {
    peso[find(i)]++;
  }
  long long ret = 1;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (peso[i]) {
      ret = (ret * peso[i]) % k;
      count++;
    }
  }
  if (count == 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < count - 2; i++) ret = (ret * n) % k;
  cout << ret << endl;
  return 0;
}
