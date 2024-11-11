#include <bits/stdc++.h>
using namespace std;
int primo[1000010], fim;
int v[5010];
vector<bool> qt;
int abs(int x) { return x > 0 ? x : -x; }
int main() {
  int n, k;
  for (int i = 0; i < 1000010; i++) primo[i] = 0;
  scanf(" %d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf(" %d", &v[i]);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) primo[abs(v[i] - v[j])]++;
  qt.resize(1000010);
  for (int i = 0; i < 1000010; i++) qt[i] = false;
  for (int i = 1; i < 1000010; i++) {
    int p = i;
    int sm = 0;
    for (int j = p; j < 1000010; j += p) sm += primo[j];
    if (sm > k * (k + 1) / 2) continue;
    qt.clear();
    bool achei = true;
    int col = 0;
    for (int j = 0; j < n; j++) {
      int x = v[j] % p;
      if (!qt[x])
        qt[x] = true;
      else {
        col++;
        if (col > k) {
          achei = false;
          break;
        }
      }
    }
    for (int j = 0; j < n; j++) qt[j] = false;
    if (achei) {
      printf("%d\n", p);
      break;
    }
  }
  return 0;
}
