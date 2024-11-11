#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, mag[101], vol = 0;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> mag[i];
    vol = vol + mag[i];
  }
  int max = mag[0];
  int index = 0;
  for (int i = 1; i < n; i++) {
    if (max <= mag[1]) {
      max = mag[i];
      index = i;
    }
  }
  vol = vol - mag[index];
  if (vol <= s)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
