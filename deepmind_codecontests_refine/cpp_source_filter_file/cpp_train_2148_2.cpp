#include <bits/stdc++.h>
using namespace std;
int n, v[200000], el;
bool car[200000 + 1];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> v[i];
  for (int i = n - 1; i; --i)
    if (!car[v[i]]) {
      el = v[i];
      car[v[i]] = 1;
    }
  cout << el;
  return 0;
}
