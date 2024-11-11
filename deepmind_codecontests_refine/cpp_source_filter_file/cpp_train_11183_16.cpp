#include <bits/stdc++.h>
using namespace std;
int num[1005];
int sum[1005];
bool cmp(int a, int b) { return a > b; }
int main() {
  int n, i, j, t;
  int temp;
  while (cin >> n) {
    memset(num, 0, sizeof(num));
    for (i = 0; i < n; i++) {
      cin >> temp;
      num[temp]++;
    }
    cin >> t;
    memset(sum, 0, sizeof(sum));
    for (i = 0; i <= t; i++) {
      sum[0] += num[i];
    }
    for (i = 1; i < 1001; i++) {
      sum[i] = sum[i - 1] - num[i - 1] + num[i + t];
    }
    sort(sum, sum + 1001, cmp);
    cout << sum[0] << endl;
  }
}
