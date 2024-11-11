#include <bits/stdc++.h>
using namespace std;
int main() {
  int l[100000];
  int r[100000];
  long n;
  cin >> n;
  int SL = 0, SR = 0;
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    SL += l[i];
    SR += r[i];
  }
  int p = -1;
  int max = abs(SL - SR);
  for (int i = 0; i < n; ++i) {
    if (abs((SL - l[i] + r[i]) - (SR - r[i] + l[i])) > max) {
      max = abs((SL - l[i] + r[i]) - (SR - r[i] + l[i]));
      p = i;
    }
  }
  cout << p + 1;
  return 0;
}
