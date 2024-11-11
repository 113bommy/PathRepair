#include <bits/stdc++.h>
using namespace std;
const int MAX = 505;
long long l1[MAX], l2[MAX], r1[MAX], r2[MAX], a1[MAX], a2[MAX];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> l1[i] >> r1[i] >> l2[i] >> r2[i];
  }
  for (int i = 0; i < q; ++i) {
    a1[i] = l1[i], a2[i] = l2[i];
    while (a1[i] == a2[i] && a2[i] <= r2[i]) {
      a2[i]++;
    }
    cout << a1[i] << ' ' << a2[i] << endl;
  }
  return 0;
}
