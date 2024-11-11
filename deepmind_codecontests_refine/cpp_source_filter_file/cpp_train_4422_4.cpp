#include <bits/stdc++.h>
using namespace std;
int a[3010], n;
int main() {
  if (0) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  };
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << n << endl;
  for (int i = 0; i < n; i++) {
    int x = a[i], v = i;
    for (int j = i; j < n; j++) {
      if (a[j] < x) {
        x = a[j];
        v = j;
      }
    }
    cout << i + 1 << " " << v + 1 << endl;
    swap(a[i], a[v]);
  }
  return 0;
}
