#include <bits/stdc++.h>
using namespace std;
const int N = 1009;
int a, b, sum = 0;
int arr[N][N], ans[N];
void llop_over(int r, int c) {
  for (int i = 0; i < r; ++i) {
    for (int g = 0; g < c; ++g) scanf("%d", &arr[i][g]);
    sum ^= arr[i][0];
  }
}
int main() {
  scanf("%d %d", &a, &b);
  llop_over(a, b);
  if (sum == 0) {
    bool flag = 0;
    for (int i = 0; i < a && !flag; ++i) {
      for (int g = 0; g < b; ++g) {
        if (arr[i][g] != arr[i][0]) {
          ans[i] = g;
          flag = true;
          break;
        }
      }
    }
    if (!flag) {
      puts("NIE");
      return 0;
    }
  }
  cout << "TAK\n";
  for (int i = 0; i < a; ++i) cout << ans[i] + 1 << " ";
}
