#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int sumr = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sumr += a[i];
  }
  sort(a.begin(), a.end());
  int suml = 0;
  for (int i = 0; i < n; i++) {
    suml += a[i];
    sumr -= a[i];
    if (suml > sumr) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}
