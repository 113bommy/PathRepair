#include <bits/stdc++.h>
using namespace std;
int Q;
bool vis[41];
int C;
map<string, int> msi;
int n, Max;
long long v[41], deg[41];
void update_maximum(long long R) {
  int Size = 0;
  while (R) {
    if (R & 1) Size++;
    R >>= 1;
  }
  Max = max(Size, Max);
}
int pickPivot(long long P) {
  int pivot = -1, Max = -1;
  memset(deg, 0, sizeof(deg));
  for (int i = 0; i < n; i++) {
    if (P & (1LL << i)) {
      if (pivot == -1) {
        pivot = i;
        Max = deg[i];
      }
      for (int j = 0; j < i; j++) {
        if ((P & (1LL << j)) && (v[i] & (1LL << j))) {
          deg[i]++;
          if (deg[i] > Max) {
            Max = deg[i];
            pivot = i;
          }
          deg[j]++;
          if (deg[j] > Max) {
            Max = deg[j];
            pivot = j;
          }
        }
      }
    }
  }
  return pivot;
}
void BronKerbosch(long long R, long long P, long long X) {
  if (!P) {
    if (!X) {
      update_maximum(R);
    }
    return;
  }
  int u = pickPivot(P | X);
  for (int i = 0; i <= n - 1; i++) {
    if (P & (~v[u]) & (1LL << i)) {
      BronKerbosch(R | (1LL << i), P & v[i], X & v[i]);
      P &= (~(1LL << i));
      X |= (1LL << i);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> Q >> n;
  for (int i = 0; i <= n - 1; i++) v[i] = ((1LL << n) - 1) & ~(1LL << i);
  int cmd;
  string str;
  for (int q = 1; q <= Q; q++) {
    cin >> cmd;
    if (cmd == 1) {
      for (int i = 0; i <= C - 1; i++)
        for (int j = i + 1; j <= C - 1; j++) {
          if (vis[i] && vis[j]) {
            v[i] &= ~(1LL << j);
            v[j] &= ~(1LL << i);
          }
        }
      memset(vis, 0, sizeof(vis));
    } else {
      cin >> str;
      if (msi.find(str) == msi.end()) {
        msi[str] = C++;
      }
      int i = msi[str];
      vis[i] = true;
    }
  }
  for (int i = 0; i <= C - 1; i++)
    for (int j = i + 1; j <= C - 1; j++) {
      if (vis[i] && vis[j]) {
        v[i] &= ~(1LL << j);
        v[j] &= ~(1LL << i);
      }
    }
  BronKerbosch(0, (1LL << C) - 1, 0);
  cout << Max << '\n';
  return 0;
}
