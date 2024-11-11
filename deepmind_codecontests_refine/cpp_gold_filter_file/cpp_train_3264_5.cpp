#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int mxcount, mncount;
  int n;
  int m;
  int max = 0;
  int min = 0;
  cin >> n >> m;
  vector<int> airports(m);
  for (int i = 0; i < m; i++) cin >> airports[i];
  sort(airports.begin(), airports.end(), greater<int>());
  vector<int> airplanes(m);
  airplanes = airports;
  int i = 0;
  mxcount = n;
  mncount = n;
  while (mxcount > 0) {
    if (i + 1 < m) {
      if (airports[i] < airports[i + 1]) {
        i++;
        continue;
      }
    }
    if (i > 0) {
      if (airports[i] <= airports[i - 1]) {
        i--;
        continue;
      }
    }
    max += airports[i];
    airports[i] += -1;
    mxcount += -1;
  }
  int j = m - 1;
  while (mncount > 0) {
    if (j + 1 < m) {
      if (airplanes[j] > airplanes[j + 1] && airplanes[j + 1] > 0) {
        j++;
        continue;
      }
    }
    if (j > 0) {
      if (airplanes[j] > airplanes[j - 1] && airplanes[j - 1] > 0) {
        j--;
        continue;
      }
    }
    min += airplanes[j];
    airplanes[j] += -1;
    mncount += -1;
    if (airplanes[j] <= 0 && j > 0) j--;
  }
  cout << max << " " << min << endl;
  return 0;
}
