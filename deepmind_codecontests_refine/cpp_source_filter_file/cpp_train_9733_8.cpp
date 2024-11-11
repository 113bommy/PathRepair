#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, min1, max1, min2, max2, min3, max3;
  cin >> n >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;
  if (max1 + min2 + min3 <= n)
    cout << n - min1 - min2 << " " << min2 << " " << min3 << endl;
  else if (max1 + max2 + min3 <= n)
    cout << max1 << " " << n - max1 - min3 << " " << min3 << endl;
  else
    cout << max1 << " " << max2 << " " << n - max1 - max2 << endl;
}
