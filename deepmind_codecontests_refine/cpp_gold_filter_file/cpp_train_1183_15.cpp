#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  long int sq[n], t, i, j;
  for (i = 0; i < n; i++) cin >> sq[i];
  if (n >= k) {
    for (i = 0; i < n - 1; i++)
      for (j = i + 1; j < n; j++)
        if (sq[i] > sq[j]) {
          t = sq[i];
          sq[i] = sq[j];
          sq[j] = t;
        }
    cout << sq[n - k] << " "
         << "0" << endl;
  } else
    cout << "-1" << endl;
  return 0;
}
