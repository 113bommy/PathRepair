#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> vet[10];
vector<int> operator-(vector<int> a, vector<int> b) {
  vector<int> c(5);
  for (int(i) = (0); (i) < (5); (i)++) c[i] = a[i] - b[i];
  return c;
}
long long mul(vector<int> a, vector<int> b) {
  long long ret = 0;
  for (int(i) = (0); (i) < (5); (i)++) ret += a[i] * b[i];
  return ret;
}
int main() {
  scanf("%d", &n);
  if (n > 6) {
    puts("0");
    return 0;
  }
  for (int(i) = (0); (i) < (n); (i)++) {
    vet[i].resize(5);
    for (int(j) = (0); (j) < (5); (j)++) scanf("%d", &vet[i][j]);
  }
  vector<int> ans;
  for (int(i) = (0); (i) < (n); (i)++) {
    int ok = 1;
    for (int(j) = (0); (j) < (n); (j)++)
      if (j != i)
        for (int(k) = (0); (k) < (n); (k)++)
          if (k != i && k != j) {
            long long v = mul(vet[j] - vet[i], vet[k] - vet[i]);
            if (v > 0) ok = 0;
          }
    if (ok) ans.push_back(i + 1);
  }
  printf("%d\n", ((int)(ans).size()));
  for (int(i) = (0); (i) < (((int)(ans).size())); (i)++)
    printf("%d%c", ans[i], i == ((int)(ans).size()) - 1 ? '\n' : ' ');
}
