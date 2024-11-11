#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  long long int c = 0, t, x, q, l, r, sum = 0;
  cin >> t;
  std::vector<int> v;
  for (int i = 0; i < t; ++i) {
    cin >> x;
    v.push_back(x);
    sum = sum + x;
  }
  cin >> q;
  long long int_sum = 0;
  for (int i = 0; i < q; ++i) {
    cin >> l >> r;
    if (sum >= l && sum <= r) {
      int_sum = sum;
      break;
    } else if (l > sum) {
      int_sum = l;
      break;
    } else {
      int_sum = -1;
    }
  }
  cout << int_sum << endl;
  return 0;
}
