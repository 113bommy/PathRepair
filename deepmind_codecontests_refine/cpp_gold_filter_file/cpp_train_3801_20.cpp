#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> yo[4000006];
int k, ck;
int main() {
  long long ans;
  double y;
  cin >> ans;
  y = 1.000 * ans;
  for (double x = 1; x <= 2000000; x++) {
    y = (2.000 * ans) / (1.00000 * x * (x + 1)) + (x - 1) / 3.000;
    if (y < x) break;
    long long z = (long long)y;
    if (y == z) {
      yo[k] = make_pair((long long)x, z);
      k++;
    }
  }
  if (ans == 1)
    ck = 1, cout << k << endl;
  else if (yo[k - 1].first == yo[k - 1].second) {
    k = 2 * k - 1;
    cout << k << endl;
    k = k / 2 + 1;
    ck = 1;
  } else {
    k = k * 2;
    cout << k << endl;
    k = k / 2;
  }
  for (int i = 0; i < k; i++) {
    printf("%I64d %I64d\n", yo[i].first, yo[i].second);
  }
  for (int i = k - ck - 1; i > -1; i--) {
    printf("%I64d %I64d\n", yo[i].second, yo[i].first);
  }
  return 0;
}
