#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int r;
int dp = 0;
int last;
bool ch;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    cin >> n >> r;
    int a[1005];
    int z = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) {
        v.push_back(i);
        z++;
      }
    }
    int flag = 0;
    int las;
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
        k++;
        if (k == 1) {
          las = i;
          if (las + 1 > r) {
            flag = 1;
            break;
          }
        } else {
          int dis = i - las;
          if (dis > (2 * r) - 1) {
            flag = 1;
            break;
          } else {
            las = i;
          }
        }
        if (k == z) {
          if (n - i > r) {
            flag = 1;
            break;
          }
        }
      }
    }
    if (flag == 1 || z == 0)
      cout << "-1";
    else {
      int ans = 0;
      int tar = r - 1;
      int last;
      int c;
      for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
          c = i;
        }
        if (i == tar) {
          last = c;
          tar = c + (2 * r) - 1;
          ans++;
        }
      }
      if (tar >= n && (n - last > r)) ans++;
      cout << ans << "\n";
    }
  }
}
