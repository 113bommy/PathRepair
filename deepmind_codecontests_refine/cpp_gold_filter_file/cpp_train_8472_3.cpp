#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long h = ceil((float)n / 2);
  if (n % 2 != 0) n++;
  if (k <= h)
    cout << k + (k - 1) << endl;
  else
    cout << k - (n - k) << endl;
}
