#include <bits/stdc++.h>
using namespace std;
const char FVD[] = "duom.txt";
const char FVR[] = "rez.txt";
int calc(int x) {
  int ret = 0;
  while (x > 0) {
    if (x % 2) ret++;
    x /= 2;
  }
  return ret;
}
int main() {
  ifstream D(FVD);
  ofstream R(FVR);
  int arr[1003];
  int n, k, m, d;
  D >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    D >> arr[i];
  }
  D >> d;
  int sol = 0;
  for (int i = 0; i < m; i++) {
    if (calc(d ^ arr[i]) <= k) {
      sol++;
    }
  }
  cout << sol << endl;
}
