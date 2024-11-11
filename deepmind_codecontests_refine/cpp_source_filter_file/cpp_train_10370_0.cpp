#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int k;
    cin >> k;
    int a[n];
    int sum = 0;
    int days = 0;
    int donated = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      days++;
      if (sum > 8) {
        donated += 8;
        sum -= 8;
      } else {
        donated += sum;
        sum = 0;
      }
      if (donated >= k) {
        cout << days << endl;
        break;
      }
    }
    if (donated < k) {
      cout << -1 << endl;
    }
  }
  return 0;
}
