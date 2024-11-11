#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> a >> b;
  v.push_back(0);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    v.push_back(k);
    sum += k;
  }
  if ((double)a * (double)v[1] / (double)sum >= b) {
    printf("0");
    return 0;
  }
  sort(v.begin() + 2, v.end());
  reverse(v.begin() + 2, v.end());
  for (int i = 2; i <= n; i++) {
    sum = sum - v[i];
    if ((double)a * (double)v[1] / (double)sum >= b) {
      printf("%d", i - 1);
      return 0;
    }
  }
  return 0;
}
