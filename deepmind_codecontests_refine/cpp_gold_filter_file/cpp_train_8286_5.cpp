#include <bits/stdc++.h>
using namespace std;
map<int, int> M, Grundy;
int n;
void init(int x) {
  for (int i = 2; i * i <= x; i++) {
    int cnt = 0;
    while (x % i == 0) {
      cnt++;
      x /= i;
    }
    M[i] |= (1 << cnt);
  }
  if (x != 1) {
    M[x] |= (1 << 1);
  }
}
int DFS(int mask) {
  if (mask == 1) return 0;
  if (Grundy.count(mask)) return Grundy[mask];
  int SG = 0;
  map<int, bool> mark;
  for (int i = 31; i >= 0; i--) {
    int newMask = (mask >> i) | (mask & ((1 << i) - 1));
    if (mask == newMask) continue;
    mark[DFS(newMask)] = true;
  }
  while (mark.count(SG)) SG++;
  Grundy[mask] = SG;
  return SG;
}
int main() {
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    init(x);
  }
  int res = 0;
  for (map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
    res ^= DFS(it->second);
  }
  cout << (res == 0 ? "Arpa" : "Mojtaba");
  return 0;
}
