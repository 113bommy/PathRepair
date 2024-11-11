#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  int m = 0, n = 0;
  cin >> m >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cout << 1 << endl;
    int tmp = 0;
    cin >> tmp;
    if (tmp == 0)
      return 0;
    else if (tmp == -1)
      vec[i] = -1;
    else
      vec[i] = 1;
  }
  int l = 1, r = m;
  int index = 0;
  while (l <= r) {
    int tmp = 0;
    if (l == r) {
      cout << l << endl;
      cin >> tmp;
      return 0;
    } else if (l == r - 1) {
      cout << r << endl;
      cin >> tmp;
      if (tmp == 0) return 0;
      cout << l << endl;
      cin >> tmp;
      return 0;
    } else {
      int mid = l + (r - l) / 2;
      cout << mid << endl;
      cin >> tmp;
      if (tmp == 0)
        return 0;
      else if (tmp == -1) {
        if (vec[index % n] == -1) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        if (vec[index % n] == -1) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }
    index++;
  }
  return 0;
}
