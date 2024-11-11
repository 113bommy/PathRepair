#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int data[100010], n, k, sum = 0, can = 0;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> data[i];
    sum += data[i] / 10;
    can = can + 10 - (data[i] / 10);
    if (data[i] % 10) can--;
    data[i] %= 10;
  }
  sort(data, data + n, cmp);
  for (int i = 0; i < n; ++i) {
    if (k >= (10 - data[i]) && data[i] != 0) {
      sum++;
      k -= (10 - data[i]);
    } else
      break;
  }
  sum += min(can, k / 10);
  cout << sum << endl;
  return 0;
}
