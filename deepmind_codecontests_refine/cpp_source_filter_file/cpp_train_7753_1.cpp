#include <bits/stdc++.h>
using namespace std;
int rows, cols;
int a[20], b[5];
vector<int> csol[5];
unsigned tried[20][11][11][11][11][11];
char sol[5][21];
bool solve(int c, int pmask) {
  if (c == cols) {
    for (int i = 0; i < rows; i++)
      if (a[i] != 0) return false;
    return true;
  }
  unsigned &tt = tried[c][a[0]][a[1]][a[2]][a[3]][a[4]];
  if (tt & 1 << pmask) return false;
  for (auto mask : csol[b[c]]) {
    tt |= 1 << pmask;
    bool ok = true;
    for (int i = 0; i < rows; i++) {
      sol[i][c] = ".*"[mask >> i & 1];
      if (!(pmask >> i & 1) and (mask >> i & 1)) {
        a[i]--;
        if (a[i] < 0) ok = false;
      }
    }
    if (ok) {
      if (solve(c + 1, mask)) return true;
    }
    for (int i = 0; i < rows; i++)
      if (!(pmask >> i & 1) and (mask >> i & 1)) a[i]++;
  }
  return false;
}
int main() {
  scanf("%d%d", &rows, &cols);
  for (int i = 0; i < rows; i++) scanf("%d", &a[i]);
  for (int i = 0; i < cols; i++) scanf("%d", &b[i]);
  for (int mask = 0; mask < 1 << rows; mask++) {
    int count = 0;
    for (int i = 0; i < rows; i++)
      if ((mask >> i & 3) == 1) count++;
    csol[count].push_back(mask);
  }
  assert(solve(0, 0));
  for (int i = 0; i < rows; i++) puts(sol[i]);
}
