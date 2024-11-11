#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int l, r, k;
  cin >> l >> r >> k;
  if (k == 1 || l == r || (r - l == 1 && l % 2 && l ^ (l + 1) >= l)) {
    cout << l << "\n1\n" << l << endl;
    return 0;
  }
  long long int num = 1, ind;
  for (int i = 0;; i++) {
    if (num > l) {
      ind = i;
      break;
    }
    num *= 2;
  }
  if (num + num / 2 <= r && k >= 3) {
    cout << "0\n3\n"
         << num - 1 << " " << num + num / 2 << " " << num + num / 2 - 1 << endl;
    return 0;
  }
  if (r - l == 1) {
    cout << (l ^ (l + 1)) << "\n2\n" << l << " " << l + 1 << endl;
    return 0;
  }
  if (l % 2) l++;
  if (l + 3 <= r && k >= 4) {
    cout << "0\n4\n"
         << l << " " << l + 1 << " " << l + 2 << " " << l + 3 << endl;
  } else {
    cout << "1\n2\n" << l << " " << l + 1 << endl;
  }
  return 0;
}
