#include <bits/stdc++.h>
using namespace std;
int main() {
  srand(time(0));
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  vector<char> c(n, false);
  int ans = 0;
  int last = a[0];
  int k = 0;
  while (k < n) {
    for (int i = 0; i < n; i++) {
      if (c[i] == false) {
        last = a[i];
        c[i] == true;
        k++;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] != last && c[i] == false) {
        c[i] = true;
        k++;
        last = a[i];
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
