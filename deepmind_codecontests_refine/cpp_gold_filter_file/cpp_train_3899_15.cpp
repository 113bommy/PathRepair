#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, v;
  cin >> n >> v;
  int fruits[3001] = {0};
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    fruits[a - 1] += b;
  }
  int cnt = 0;
  cnt += min(v, fruits[0]);
  fruits[0] -= v;
  for (int i = 1; i < 3001; i++) {
    if (fruits[i - 1] > 0) {
      if (fruits[i - 1] >= v) {
        cnt += v;
        fruits[i - 1] -= v;
      } else {
        cnt += min(fruits[i], v - fruits[i - 1]) + fruits[i - 1];
        fruits[i] -= (v - fruits[i - 1]);
        fruits[i - 1] = 0;
      }
    } else {
      cnt += min(v, fruits[i]);
      fruits[i] -= v;
    }
  }
  cout << cnt << "\n";
}
