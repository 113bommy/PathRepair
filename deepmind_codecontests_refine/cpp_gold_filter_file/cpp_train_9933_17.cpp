#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
const int INF = 0x7fffffff;
int sum[maxn];
int main() {
  int n, k;
  cin >> n >> k;
  cin >> sum[0];
  for (int i = 1; i < n; i++) {
    cin >> sum[i];
    sum[i] += sum[i - 1];
  }
  int min = INF;
  int index = 0;
  for (int i = k - 1; i < n; i++) {
    if (min > (sum[i] - sum[i - k])) {
      index = i - k + 1;
      min = sum[i] - sum[i - k];
    }
  }
  cout << index + 1 << endl;
  return 0;
}
