#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, L, v1, v2;
  cin >> d >> L >> v1 >> v2;
  double time = (double)(L - d) / (v1 + v2);
  cout << setprecision(6) << time;
}
