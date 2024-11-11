#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  pair<int, int> a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  if (n == 1) {
    cout << 1;
    return 0;
  }
  sort(a, a + n);
  if (a[0].first == a[1].first) {
    cout << "Still Rozdil";
  } else {
    cout << a[0].second + 1;
  }
  return 0;
}
