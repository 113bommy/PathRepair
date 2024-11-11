#include<bits/stdc++.h>
using namespace std;

long f(int x) {
  if (x % 2) return x - 1;
  return x;
}

int main() {
  int I, O, J, L;
  {
    int x; cin >> I >> O >> x >> J >> L;
  }
  long r = 0;
  if (I && J && L) {
    r = 3 + f(I-1) + f(J-1) + f(L-1);
  }
  r = max(r, f(I) + f(J) + f(L));
  cout << r + O << endl;
}
