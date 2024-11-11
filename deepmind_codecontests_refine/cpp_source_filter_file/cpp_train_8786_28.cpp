#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, m;
  int sum1 = 0, sum2 = 0;
  int tmp;
  int arr[300], i;
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> tmp;
    sum1 += tmp;
    arr[i] = tmp;
  }
  cin >> x >> y;
  for (i = 0; i < m; i++) {
    if (sum1 >= x && sum1 <= y && sum2 >= x && sum2 <= y) {
      cout << i + 2 << endl;
      return 0;
    } else {
      sum1 -= arr[i];
      sum2 += arr[i];
    }
  }
  cout << "0" << endl;
}
