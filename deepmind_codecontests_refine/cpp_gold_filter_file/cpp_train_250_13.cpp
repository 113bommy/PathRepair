#include <bits/stdc++.h>
using namespace std;
const int N = 210;
const int INF = 0x3f3f3f3f;
int n, k;
int a[N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int ans = -INF;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      vector<int> in, out;
      for (int l = i; l <= j; l++) in.push_back(a[l]);
      for (int l = 0; l < i; l++) out.push_back(a[l]);
      for (int l = j + 1; l < n; l++) out.push_back(a[l]);
      sort(in.begin(), in.end());
      sort(out.begin(), out.end(), greater<int>());
      for (int l = 0, s = 0, pos = 0;
           l < out.size() && pos < in.size() && s < k;) {
        if (out[l] > in[pos]) {
          swap(out[l], in[pos]);
          pos++;
          s++;
          l++;
        } else {
          break;
        }
      }
      int cur = accumulate(in.begin(), in.end(), 0);
      ans = max(ans, cur);
    }
  }
  printf("%d\n", ans);
  return 0;
}
