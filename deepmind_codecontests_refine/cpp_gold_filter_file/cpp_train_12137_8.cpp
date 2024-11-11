#include <bits/stdc++.h>
using namespace std;
void fl() {}
int main() {
  fl();
  pair<int, int> a[1000];
  int n, s = 0;
  cin >> n;
  for (int i = 0; i < n and cin >> a[i].first; i++)
    s += a[i].first, a[i].second = i;
  if (a[0].first == 0 or s < n - 1) return cout << -1, 0;
  sort(a + 1, a + n, greater<pair<int, int> >());
  cout << n - 1 << "\n";
  int i0 = 0;
  for (int i = 1; i < n; i++) {
    cout << a[i0].second + 1 << " " << a[i].second + 1 << endl;
    a[i0].first--;
    if (!a[i0].first) i0++;
  }
  return 0;
}
