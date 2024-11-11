#include <bits/stdc++.h>
using namespace std;
int v[200005], n, copie, k, first = 1, last;
long long dmg;
char c[200005];
bool cmp(int a, int b) { return a > b; }
void citire() {
  cin >> n >> k;
  copie = k;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  c[n + 1] = '*';
  for (int i = 1; i <= n; ++i) {
    if (c[i] == c[i + 1])
      last = i + 1;
    else {
      if (last - first + 1 > 1) {
        sort(v + first, v + last + 1, cmp);
        for (int i = first; i <= last && k; ++i) {
          dmg += v[i];
          k--;
        }
      } else
        dmg += v[i];
      k = copie;
      first = i + 1;
    }
  }
  cout << dmg;
}
int main() {
  citire();
  return 0;
}
