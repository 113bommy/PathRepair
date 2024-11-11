#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v(11);
  for (int &i : v) cin >> i;
  reverse(v.begin(), v.end());
  for (int i : v) {
    float x = 0;
    if (i >= 0) {
      x = (float)(i * i * i * 5) + sqrt((float)i);
    } else {
      x = (float)(i * i * i * 5) + sqrt((float)-i);
    }
    if (x <= 5000) {
      printf("f(%d) = %.2f\n", i, x);
    } else {
      printf("f(%d) = MAGNA NIMIS!\n", i);
    }
  }
}
