#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, q = 0, p = 0;
  cin >> n >> p;
  int arr[104] = {0};
  for (int i = 1; i <= p; i++) cin >> arr[i];
  cin >> q;
  for (int i = p + 1; i <= q + p; i++) cin >> arr[i];
  int cntr = 0;
  sort(arr + 0, arr + p + q + 1);
  int dif = abs(n - (p + q));
  for (int i = 0; i <= n + dif; i++) {
    for (int j = 0; j < q + p; j++) {
      if (arr[j] == i) {
        cntr++;
        break;
      }
    }
  }
  if (cntr == n)
    cout << "I become the guy." << endl;
  else
    cout << "Oh, my keyboard!" << endl;
  return 0;
}
