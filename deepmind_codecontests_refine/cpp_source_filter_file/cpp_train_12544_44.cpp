#include <bits/stdc++.h>
using namespace std;
void RI() {}
template <typename... T>
void RI(int& head, T&... tail) {
  scanf("%d", &head);
  RI(tail...);
}
const long long N = 25 * 1e8, L = 1005;
vector<int> V[L], X, Y;
int cmp(const int a, const int b) { return Y[a] < Y[b]; }
int main() {
  int n;
  RI(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    RI(x, y);
    X.push_back(x);
    Y.push_back(y);
    V[x / 1000].push_back(i);
  }
  for (int i = 0; i < L; i++) {
    sort(V[i].begin(), V[i].end(), cmp);
    if (i & 1) reverse(V[i].begin(), V[i].end());
    for (int id : V[i]) printf("%d ", id);
  }
  return 0;
}
