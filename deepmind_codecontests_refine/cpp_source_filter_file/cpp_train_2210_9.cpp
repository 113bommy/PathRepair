#include <bits/stdc++.h>
using namespace std;
int main() {
  int fr[25], n, i, v[100005], rez = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> v[i];
    if (v[i] >= 0)
      fr[v[i] + 11]++;
    else
      fr[abs(v[i])]++;
  }
  for (i = 1; i <= 10; i++) {
    rez += fr[i] * fr[i + 11];
  }
  rez = rez + fr[11] * (fr[11] - 1) / 2;
  cout << rez;
}
