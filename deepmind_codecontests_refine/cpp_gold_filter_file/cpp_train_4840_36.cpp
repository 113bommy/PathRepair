#include <bits/stdc++.h>
using namespace std;
int k[1000][10000];
int wer[100000];
int main() {
  long long n;
  cin >> n;
  int i;
  int m;
  int q = 0;
  for (i = 0; i < n; i++) {
    for (m = 0; m < n; m++) {
      cin >> k[i][m];
    }
  }
  int c = 0;
  int d = 0;
  for (i = 0; i < n; i++) {
    for (m = 0; m < n; m++) {
      if (k[i][m] == 0 || k[i][m] == -1 || k[i][m] == 2) c++;
    }
    if (c == n) {
      wer[d] = i + 1;
      d++;
      q++;
    }
    c = 0;
  }
  if (q == 0)
    cout << 0;
  else {
    cout << q << "\n";
    for (i = 0; i < d; i++) cout << wer[i] << " ";
  }
  return 0;
}
