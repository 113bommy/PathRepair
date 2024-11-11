#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int w, h, k, j, g, area = 0;
  long long int t, i;
  cin >> t;
  for (i = 1; i <= t; i++) {
    long long int max1 = 0, max2 = 0, max3 = 0, max4 = 0, min1 = 10000000,
                  min2 = 10000000, min3 = 10000000, min4 = 10000000;
    area = 0;
    cin >> w >> h;
    cin >> k;
    for (j = 1; j <= k; j++) {
      cin >> g;
      min1 = min(min1, g);
      max1 = max(max1, g);
    }
    area = max(area, (max1 - min1) * h);
    cin >> k;
    for (j = 1; j <= k; j++) {
      cin >> g;
      min2 = min(min2, g);
      max2 = max(max2, g);
    }
    area = max(area, (max2 - min2) * h);
    cin >> k;
    for (j = 1; j <= k; j++) {
      cin >> g;
      min3 = min(min3, g);
      max3 = max(max3, g);
    }
    area = max(area, (max3 - min3) * w);
    cin >> k;
    for (j = 1; j <= k; j++) {
      cin >> g;
      min4 = min(min4, g);
      max4 = max(max4, g);
    }
    area = max(area, (max4 - min4) * w);
    cout << area << endl;
  }
}
