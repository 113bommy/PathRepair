#include <bits/stdc++.h>
using namespace std;
int n, k, a[103], cnt, temp;
int main() {
  cin >> n >> k;
  for (int i = 0; i < 2 * n + 1; i++) cin >> a[i];
  temp = 1;
  while (cnt < k) {
    if ((a[temp] > a[temp - 1] + 1) and (a[temp] > a[temp + 1] + 1)) {
      cnt++;
      a[temp]--;
    }
    temp += 2;
  }
  for (int i = 0; i < 2 * n + 1; i++) cout << a[i] << " ";
  return 0;
}
