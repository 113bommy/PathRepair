#include <bits/stdc++.h>
using namespace std;
const int MD = 400;
int i, n, k;
int b[300], num[300][MD], dig[300];
void max_fill(int index, int x) {
  dig[index] = MD;
  while (x) {
    dig[index]--;
    int add = min(x, 9 - num[index][dig[index]]);
    num[index][dig[index]] += add;
    x -= add;
  }
  dig[index] = 0;
  for (int i = 0; i < MD; i++)
    if (num[index][i] > 0) {
      dig[index] = i;
      break;
    }
}
int main() {
  cin >> n;
  for (i = 0; i < n; i++) cin >> b[i];
  max_fill(0, b[0]);
  for (i = 1; i < n; i++) {
    int cur_sum = 0, rem_sum = b[i];
    bool done = false;
    for (int j = dig[i - 1]; j < MD; j++) {
      if (cur_sum + num[i - 1][j] >= b[i]) {
        int k = j - 1;
        while (num[i][k] == 9) {
          num[i][k--] = 0;
          rem_sum += 9;
        }
        num[i][k] += 1;
        max_fill(i, rem_sum - 1);
        done = true;
        break;
      } else if (j < MD - 1) {
        cur_sum += num[i - 1][j];
        num[i][j] = num[i - 1][j];
        rem_sum -= num[i][j];
      }
    }
    if (!done) max_fill(i, rem_sum);
  }
  for (i = 0; i < n; i++) {
    bool started = false;
    for (int j = 0; j < MD; j++)
      if (num[i][j] || started) {
        cout << num[i][j];
        started = true;
      }
    cout << endl;
  }
}
