#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  long long ans[q];
  for (int t = 0; t < q; t++) {
    long long n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    if (a <= b / 2)
      ans[t] = n * a;
    else
      ans[t] = (((n - 1) / 2) * b) + (a * (n % 2));
  }
  for (int i = 0; i < q; i++) cout << ans[i] << endl;
  return 0;
}
