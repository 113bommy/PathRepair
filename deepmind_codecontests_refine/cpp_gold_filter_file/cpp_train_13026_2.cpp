#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int h[5001];
  memset(h, 0, sizeof(h));
  int v[n];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    h[v[i]]++;
  }
  if (*max_element(h, h + 5001) > k) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  int f = 1;
  int h2[5001];
  for (int i = 0; i < 5001; i++) {
    h2[i] = min(f, k - h[i] + 1);
    f += h[i];
  }
  for (int i = 0; i < n; i++) {
    cout << h2[v[i]]++;
    cout << " ";
  }
  return 0;
}
