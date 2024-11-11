#include <bits/stdc++.h>
using namespace std;
int main() {
  float L, D, v1, v2;
  float time = 0;
  cin >> L >> D >> v1 >> v2;
  time = abs(L - D) / (v1 + v2);
  cout << fixed << setprecision(6) << time << endl;
}
