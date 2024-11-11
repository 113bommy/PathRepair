#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, min1, max1, min2, max2, min3, max3;
  cin >> n >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;
  long long int left = n - (min1 + min2 + min3);
  while (min1 < max1 and left) {
    min1++;
    left--;
  }
  while (min2 < max2 and left) {
    min2++;
    left--;
  }
  while (left) {
    min3++;
    left--;
  }
  cout << min1 << " " << min2 << " " << min3 << endl;
  return 0;
}
