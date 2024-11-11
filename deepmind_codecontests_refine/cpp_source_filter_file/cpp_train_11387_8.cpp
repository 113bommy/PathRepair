#include <bits/stdc++.h>
using namespace std;
int Mod, n, Cnt, Count;
pair<int, int> L[200005];
long long Ans, Fact[200005], Sum[200005];
int POW(int x, int y) {
  if (y == 0) return 1;
  long long u = POW(x, y / 2);
  u = u * u % Mod;
  if (y % 2) u = u * x % Mod;
  return u;
}
int main() {
  cin >> n;
  int u;
  for (int i = 1; i <= n; i++) {
    cin >> u;
    L[i] = make_pair(u, i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> u;
    L[n + i] = make_pair(u, i);
  }
  cin >> Mod;
  Fact[0] = 1;
  for (int i = 1; i <= 2 * n; i++) {
    Cnt = 0;
    u = i;
    while (u % 2 == 0) {
      u /= 2;
      Cnt++;
    }
    Fact[i] = Fact[i - 1] * u % Mod;
    Sum[i] = Sum[i - 1] + Cnt;
  }
  sort(L + 1, L + 2 * n + 1);
  L[2 * n + 1].first = L[0].first = 1e9;
  Ans = 1;
  Cnt = Count = 0;
  for (int i = 1; i <= 2 * n + 1; i++) {
    if (L[i].first != L[i - 1].first) {
      Ans = Ans * Fact[Cnt] % Mod;
      Ans = Ans * POW(2, Sum[Cnt] - Count) % Mod;
      Cnt = 1;
      Count = 0;
    }
    if (L[i].first == L[i - 1].first) {
      Cnt++;
      if (L[i].second == L[i - 1].second) Count++;
    }
  }
  cout << Ans;
}
