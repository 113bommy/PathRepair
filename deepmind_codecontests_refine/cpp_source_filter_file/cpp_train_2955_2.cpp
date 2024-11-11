#include <bits/stdc++.h>
using namespace std;
struct node {
  int val, inx;
};
int a[100010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  bool sf = 0;
  int mid = 2, p = 0, w = 0;
  while (a[1] == a[mid] && mid <= n) mid++;
  if (a[1] < a[mid]) {
    for (int i = mid + 1; i < n; i++)
      if (a[i + 1] < a[i]) {
        p = i;
        w = i + 1;
        sf = 1;
        break;
      }
  } else {
    for (int i = mid + 1; i < n; i++)
      if (a[i + 1] > a[i]) {
        p = i;
        w = i + 1;
        sf = 1;
        break;
      }
  }
  if (sf) {
    cout << "3\n";
    cout << 1 << ' ' << p << ' ' << w << "\n";
  } else
    cout << "0\n";
  return 0;
}
