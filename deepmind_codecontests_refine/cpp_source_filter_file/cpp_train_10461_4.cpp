#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, w;
  double sum = 0;
  cin >> k >> n >> w;
  for (int i = 1; i <= w; i++) sum = sum + i * k;
  if (sum > k)
    cout << sum - n;
  else
    cout << "0";
  return 0;
}
