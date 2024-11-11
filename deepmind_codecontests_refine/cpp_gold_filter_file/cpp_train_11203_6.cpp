#include <bits/stdc++.h>
using namespace std;
const int maxN = 50000 + 10;
int n;
int B[maxN];
vector<pair<int, int>> VB;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &B[i]);
  for (int i = 0; i < n; i++) {
    VB.push_back(make_pair(B[i] + B[(i + 1) % n], i));
  }
  sort(VB.begin(), VB.end());
  for (int i = 0; i < n; i++) {
    auto p = VB[i];
    B[p.second] = i;
  }
  for (int i = 0; i < n; i++) printf("%d%c", B[i], (i == n - 1) ? '\n' : ' ');
  return 0;
}
