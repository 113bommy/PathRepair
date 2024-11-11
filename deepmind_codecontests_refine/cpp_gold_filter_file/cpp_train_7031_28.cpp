#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, A[4];
  cin >> A[0] >> A[1] >> A[2] >> A[3] >> a >> b;
  int min = *min_element(A, A + 4);
  if (min < a || (min == 1 && a != 0))
    cout << 0 << "\n";
  else if (min <= b)
    cout << min - a << "\n";
  else
    cout << b - a + 1 << "\n";
}
