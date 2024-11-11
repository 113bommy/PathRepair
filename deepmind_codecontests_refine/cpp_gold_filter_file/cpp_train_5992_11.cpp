#include <bits/stdc++.h>
using namespace std;
int a[105];
pair<int, int> p[105];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[i] = make_pair(a[i], i);
  }
  sort(p, p + n);
  for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
    cout << p[i].second + 1 << " " << p[j].second + 1 << '\n';
  }
}
