#include <bits/stdc++.h>
using namespace std;
struct ak {
  long long k;
  long long a;
};
int main() {
  int n;
  cin >> n;
  vector<ak> data(n);
  for (int i = 0; i < n; i++) {
    cin >> data[i].k;
    cin >> data[i].a;
  }
  sort(data.begin(), data.end(),
       [](const ak &a, const ak &b) { return a.k > b.k; });
  long long r = data[0].k + 1;
  bool allok = false;
  double l4 = 2 * log(2);
  while (!allok) {
    allok = true;
    for (int i = 0; i < n; i++) {
      ak cur = data[i];
      double new_r = log(cur.a) / l4;
      if ((new_r - (r - cur.k)) > 10e-15) {
        allok = false;
        r = (new_r > (r + 1) ? new_r : r + 1);
        break;
      }
    }
  }
  cout << r;
  return 0;
}
