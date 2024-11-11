#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
double n, h;
int main() {
  cin >> n >> h;
  for (int i = (1); i <= (int)(n - 1); ++i) printf("%.6f ", h * sqrt(i / n));
}
