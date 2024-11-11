#include <bits/stdc++.h>
const int N = 100100;
const long long mod = 1e9 + 7;
using namespace std;
int n, Xa, Ya, Xb, Yb;
int Smallest(int a, int b, int c, int d) {
  int min_ = a;
  if (min_ < b) min_ = b;
  if (min_ < c) min_ = c;
  if (min_ < d) min_ = d;
  return min_;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> Xa >> Ya >> Xb >> Yb;
  if ((Xa == Xb && (Xa == 0 || Xa == n)) || (Ya == Yb && (Ya == 0 || Ya == n)))
    cout << abs(Xa - Xb) + abs(Ya - Yb) << "\n";
  else
    cout << Smallest(abs(0 - Xa) + abs(0 - Ya) + abs(0 - Xb) + abs(0 - Yb),
                     abs(0 - Xa) + abs(n - Ya) + abs(0 - Xb) + abs(n - Yb),
                     abs(n - Xa) + abs(0 - Ya) + abs(n - Xb) + abs(0 - Yb),
                     abs(n - Xa) + abs(n - Ya) + abs(n - Xb) + abs(n - Yb))
         << "\n";
  return 0;
}
