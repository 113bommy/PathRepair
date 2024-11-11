#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n >> d;
  int need[n], avail[n];
  for (int i = 0; i < n; i++) cin >> need[i];
  for (int i = 0; i < n; i++) cin >> avail[i];
  int low = 1, high = 2001;
  int goat;
  while (low <= high) {
    int mid = (low + high) / 2;
    int temp = d;
    bool works = true;
    for (int i = 0; i < n; i++) {
      if (need[i] * mid > avail[i]) {
        temp -= ((need[i] * mid) - avail[i]);
      }
    }
    if (temp < 0) works = false;
    if (works) {
      goat = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  cout << goat << '\n';
  return 0;
}
