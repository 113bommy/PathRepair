#include <bits/stdc++.h>
using namespace std;
const int MAXA = 105;
int n, v[MAXA], k;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> k, v[k]++;
  k = 0;
  for (int i = 0; i < n; i++) k += v[i] / 2;
  cout << k / 2;
}
