#include <bits/stdc++.h>
using namespace std;
int arr[100005][2];
int mins[100005];
int row[100005][2];
int main() {
  int n, m;
  cin >> n >> m;
  int nl = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[j][nl];
      if (i == 0) {
        row[j][nl] = 0;
      } else if (arr[j][nl] >= arr[j][1 - nl]) {
        row[j][nl] = row[j][1 - nl];
      } else {
        row[j][nl] = i;
      }
    }
    mins[i] = 1000000;
    for (int j = 0; j < m; j++) {
      mins[i] = min(mins[i], row[j][nl]);
    }
    nl = 1 - nl;
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int li, ri;
    cin >> li >> ri;
    li--;
    ri--;
    if (mins[ri] <= li)
      cout << "Yes " << endl;
    else
      cout << "No" << endl;
  }
}
