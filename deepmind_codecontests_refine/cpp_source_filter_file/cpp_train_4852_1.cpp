#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, a;
  cin >> n >> a;
  double angd = 180 / n;
  double ang = 185, angt, angc = angd;
  int min_d = 1;
  cout << 2 << " " << 1 << " ";
  for (int i = 3; i <= n; i++, angc += angd) {
    angt = a - angc;
    if (angt < 0) angt = -angt;
    if (angt < ang) {
      min_d = i;
      ang = angt;
    }
  }
  cout << min_d << endl;
  return 0;
}
