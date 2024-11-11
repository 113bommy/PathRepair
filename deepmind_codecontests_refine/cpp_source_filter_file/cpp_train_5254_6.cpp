#include <bits/stdc++.h>
using namespace std;
bool nr[1000000 + 10];
int mxm[1000000 + 10];
int main() {
  int n, c;
  cin >> n;
  while (n--) {
    cin >> c;
    nr[c] = true;
  }
  for (int i = 2; i <= 1000000; i++)
    if (nr[i])
      mxm[i] = i;
    else
      mxm[i] = mxm[i - 1];
  int best = 0;
  for (int i = 2; i < 1000000; i++)
    if (nr[i])
      for (int j = 2; i * j <= 1000000 + 1; j++)
        if (mxm[i * j - 1] % i > best) best = mxm[i * j - 1] % i;
  cout << best;
  return 0;
}
