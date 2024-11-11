#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 2 * 1e6 + 5;
const long long int modn = 1e9 + 7;
long long int Z, len, fir, sec, num, sum;
long long int all[maxn];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> fir >> sec;
  for (int i = 1; i <= 1000; i++) {
    if (i * i <= fir)
      num = fir - i * i;
    else
      break;
    if (num * num == sec - i) sum++;
  }
  cout << sum;
  return 0;
}
