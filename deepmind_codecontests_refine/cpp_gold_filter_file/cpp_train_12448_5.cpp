#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
int n, k, p[N], vis[N];
vector<int> cycsizes;
bitset<N> oldKn, newKn;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      int j = i;
      cycsizes.push_back(0);
      while (!vis[j]) {
        cycsizes.back()++;
        vis[j] = 1;
        j = p[j];
      }
    }
  }
  sort(cycsizes.begin(), cycsizes.end());
  vector<int> ap(n + 1);
  for (auto it : cycsizes) ++ap[it];
  int K = k;
  int minim = 0, maxim = 0;
  for (int i = 0; i < cycsizes.size(); ++i) {
    int take = cycsizes[i] / 2;
    maxim += 2 * min(K, take);
    K -= min(K, take);
  }
  for (int i = 0; i < cycsizes.size(); ++i) {
    if (K > 0 && cycsizes[i] % 2) ++maxim, K--;
  }
  vector<int> Rucs;
  for (int i = 1; i <= k; ++i) {
    int val = ap[i];
    for (int j = 0; (1 << j) <= val; ++j) {
      Rucs.push_back(i * (1 << j));
      val -= 1 << j;
    }
    if (val) Rucs.push_back(val * i);
  }
  oldKn[0] = 1;
  for (int i = 0; i < Rucs.size(); ++i) {
    newKn = oldKn;
    newKn |= oldKn << Rucs[i];
    oldKn = newKn;
  }
  if (newKn[k])
    minim = k;
  else
    minim = k + 1;
  if (k == 0) minim = maxim = 0;
  cout << minim << ' ' << maxim;
}
