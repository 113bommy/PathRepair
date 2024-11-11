#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a;
  vector<int> v1(100001);
  vector<int> maxr(100001);
  for (int i = 0; i < a; i++) cin >> v1[i];
  cin >> b;
  vector<int> v2(100001);
  for (int i = 0; i < b; ++i) cin >> v2[i];
  int lv2 = b - 1;
  int x = 0;
  for (int i = 0; i < a; ++i) {
    for (int j = b - 1; j >= 0; j--) {
      if (v2[j] % v1[i] == 0) {
        maxr[x] = v2[lv2] / v1[i];
        x++;
        break;
      }
    }
  }
  int maxxr = *max_element(maxr.begin(), maxr.end());
  int cnt = 0;
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      if (v2[j] % v1[i] == 0 && v2[j] / v1[i] == maxxr) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
