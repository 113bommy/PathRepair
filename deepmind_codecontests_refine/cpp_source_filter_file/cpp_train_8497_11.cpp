#include <bits/stdc++.h>
using namespace std;
int H, a[200009], p[200009] = {}, p1[200009];
int N = 0;
inline void solve(int k) {
  int n = 1, prev = 0, s1, sprev;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < a[i]; ++j) p[n] = p1[n] = prev, n++;
    if (i == k) s1 = n, sprev = n - 2;
    prev = n - 1;
  }
  p1[s1] = sprev;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> H;
  for (int i = 0; i < H; ++i) {
    cin >> a[i];
    N += a[i];
  }
  bool found = false;
  for (int i = 1; i < H; ++i) {
    if (a[i] > 1 && a[i - 1] > 1) {
      found = true;
      solve(i - 1);
      break;
    }
  }
  if (!found)
    cout << "perfect\n";
  else {
    cout << "ambiguous\n";
    for (int i = 1; i < N + 1; ++i) cout << p[i] << " \n"[i == N];
    for (int i = 1; i < N + 1; ++i) cout << p1[i] << " \n"[i == N];
  }
}
