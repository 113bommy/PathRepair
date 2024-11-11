#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int deg;
  cin >> deg;
  deg %= 360;
  long long int ans[4];
  ans[0] = deg;
  for (int i = 1; i < 4; i++) ans[i] = ((ans[i - 1] - 90)) % 360;
  for (int i = 0; i < 4; i++) ans[i] = abs(ans[i]);
  for (int i = 0; i < 4; i++)
    if (ans[i] > 180) ans[i] = 360 - ans[i];
  int mini = 360;
  int k = -1;
  for (int i = 0; i < 4; i++)
    if (ans[i] < mini) {
      mini = ans[i];
      k = i;
    }
  cout << k;
}
