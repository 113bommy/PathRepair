#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, w;
  long int sum = 0;
  cin >> k >> n >> w;
  for (int i = 1; i <= w; i++) sum = sum + i * k;
  if (sum > n)
    cout << sum - n;
  else
    cout << "0";
  return 0;
}
