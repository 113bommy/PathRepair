#include <bits/stdc++.h>
using namespace std;
const int ORX = 3, ANDX = 1, XORX = 2;
const int MAXN = 500000 + 10;
int X[MAXN];
int O[MAXN];
int bit_of(int num, int b) {
  if (num & (1 << b)) return 1;
  return 0;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> X[i] >> O[i];
  }
  int ret = X[0];
  for (int i = 1; i < n; i++) {
    int s = X[i];
    int d = O[i];
    while (s < ret) {
      s = s + d;
    }
    ret = s;
  }
  cout << ret << endl;
  ;
  return 0;
}
