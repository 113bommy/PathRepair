#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0, q = 0, p = 0, kol = 0;
  cin >> n;
  int a[n + 10];
  vector<int> us(n + 10, 0);
  vector<int> v;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      int f2 = 0, f3 = 0;
      for (int j = i + 1; j <= n; j++) {
        if (us[j] == 0 && a[j] == 2 && f2 == 0) {
          f2 = j;
          us[j] = 1;
        }
        if (us[j] == 0 && a[j] == 3 && f3 == 0) {
          f3 = j;
          us[j] = 1;
        }
      }
      if (f2 != 0 && f3 != 0) {
        kol++;
        v.push_back(i);
        v.push_back(f2);
        v.push_back(f3);
      }
    }
  }
  cout << kol << endl;
  for (int i = 0; i < v.size(); i += 3)
    cout << v[i] << " " << v[i + 1] << " " << v[i + 2] << "\n";
}
