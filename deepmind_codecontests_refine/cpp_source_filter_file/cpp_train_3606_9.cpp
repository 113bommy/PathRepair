#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
bool isPerfect[maxn];
vector<int> v;
void init() {
  memset(isPerfect, false, sizeof(isPerfect));
  for (int i = 1; i <= 1000; i++) {
    isPerfect[i * i] = true;
  }
}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }
  sort((v).begin(), (v).end());
  reverse((v).begin(), (v).end());
  for (int i = 0; i <= (int)v.size() - 1; i++) {
    if ((v[i] <= 0) or (!isPerfect[v[i]])) {
      printf("%d\n", v[i]);
      return;
    }
  }
}
int main() {
  init();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
