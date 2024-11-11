#include <bits/stdc++.h>
using namespace std;
int n, q, a[200009], las[200009], mx[200009], qu[200009];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    x--;
    if (x == 0) {
      int v;
      cin >> x >> v;
      x--;
      las[x] = i;
      a[x] = v;
    } else {
      cin >> x;
      qu[i] = x;
    }
  }
  for (int i = n - 1; i >= 0; i--) mx[i] = max(mx[i + 1], qu[i]);
  for (int i = 0; i < n; i++) {
    a[i] = max(a[i], mx[las[i]]);
    cout << a[i] << " ";
  }
}
