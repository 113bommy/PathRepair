#include <bits/stdc++.h>
using namespace std;
const int N = 1;
const int inf = 1e9;
const int M = 1e9;
int k;
int main() {
  scanf("%d", &k);
  if (k & 1) {
    puts("YES");
    int n = 4 * (k - 1) + 2;
    int m = 2 * (k - 1) * (k - 1) + 2 * (k - 1) + 1 + (k - 1) / 2;
    cout << n << " " << m << endl;
    int cnt = 2 * k - 1;
    for (int i = 2; i <= k; i++) cout << 1 << " " << i << endl;
    for (int i = 2; i <= k; i++)
      for (int j = 1; j < k; j++) cout << i << " " << j + k << endl;
    for (int i = 1; i < k; i += 2) cout << k + i << " " << k + i + 1 << endl;
    for (int i = 2; i <= k; i++) cout << cnt + 1 << " " << cnt + i << endl;
    for (int i = 2; i <= k; i++)
      for (int j = 1; j < k; j++) cout << cnt + i << " " << cnt + j + k << endl;
    for (int i = 1; i < k; i += 2)
      cout << cnt + k + i << " " << cnt + k + i + 1 << endl;
    cout << 1 << " " << cnt + 1 << endl;
  } else
    puts("NO");
  return 0;
}
