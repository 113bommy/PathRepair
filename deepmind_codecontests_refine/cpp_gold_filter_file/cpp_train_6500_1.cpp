#include <bits/stdc++.h>
using namespace std;
int n, m, type, l, r;
long long t[100009], prefiksy1[100009], prefiksy2[100009];
int main() {
  cin >> n;
  prefiksy1[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    prefiksy1[i + 1] = prefiksy1[i] + t[i];
  }
  sort(t, t + n);
  prefiksy2[0] = 0;
  for (int i = 0; i < n; i++) prefiksy2[i + 1] = prefiksy2[i] + t[i];
  cin >> m;
  while (m--) {
    cin >> type >> l >> r;
    if (type == 1)
      cout << prefiksy1[r] - prefiksy1[l - 1] << endl;
    else
      cout << prefiksy2[r] - prefiksy2[l - 1] << endl;
  }
}
