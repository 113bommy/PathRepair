#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long LINF = 1e18;
void solve() {
  vector<int> vec;
  int cur = 1;
  int add = 1;
  int n;
  scanf("%d", &n);
  while (1) {
    if (add + add <= n - cur) {
      int kir = add, kan = add + add;
      while (kir < kan) {
        long long mid = (kir + kan + 1) / 2;
        if (cur + mid + mid > n)
          kan = mid - 1;
        else
          kir = mid;
      }
      vec.push_back(kir - add);
      add = kir;
      cur += add;
    } else {
      vec.push_back(n - cur - add);
      add = (n - cur);
      cur += add;
      break;
    }
  }
  printf("%lu\n", vec.size());
  for (int i = 0; i < vec.size(); i++)
    printf("%d%c", vec[i], (i == vec.size() - 1) ? '\n' : ' ');
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
